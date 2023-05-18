// Copyright 2023 Kosmatoff

#include <filesystem>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include <regex>

#include "config.hpp"

static const std::string defaultIpServer = "10.20.0.1/24";
static const std::string defaultPort = "51285";
static const std::string defaultPath = "/etc/wireguard/";
static const std::string defaultPostUp = "iptables -A FORWARD -i %i -j ACCEPT; iptables -t nat -A POSTROUTING -o $(ip a | grep -oP '(?<=2: ).*' | grep -o '^....') -j MASQUERADE";
static const std::string defaultPostDown = "iptables -D FORWARD -i %i -j ACCEPT; iptables -t nat -D POSTROUTING -o $(ip a | grep -oP '(?<=2: ).*' | grep -o '^....') -j MASQUERADE";


static void parseIpForSearch(std::string& ip) {
    std::size_t pos = ip.find_last_of(".");
    ip = ip.substr(pos + 1); // output "101"
}

// принимает самый последний элемент, если от него давно не было handshake 
// возвращает значени true
static bool isPeerLatestHadshake(const std::string& info,
                                std::string& peer, std::string& ips
) {
    std::istringstream iss(info);
    std::string line;
    bool flag = false;
    while (std::getline(iss, line)) {
        if (line.find("latest handshake") != std::string::npos) {
            if (line.find("hours") != std::string::npos) {
                flag = false;
            } else {
                flag = true;
            }
        } else if (line.find("peer:")) {
            std::istringstream publicKey(line);
            publicKey.ignore(6);
            publicKey >> peer;

            // Extract allowed IPs
            std::getline(publicKey, line);
            std::istringstream ipsStream(line);
            ipsStream.ignore(15);  // Skip "  allowed ips: "
            std::getline(ipsStream, ips, ',');
        }
    }
    return flag;
}

static std::string extractIPValue(const std::string& ipAddress) {
    // Находим позицию последней точки
    size_t lastDotPos = ipAddress.find_last_of('.');

    // Находим позицию символа "/"
    size_t slashPos = ipAddress.find('/');

    // Извлекаем значение между последней точкой и символом "/"
    std::string value = ipAddress.substr(lastDotPos + 1, slashPos - lastDotPos - 1);

    return value;
}

// данная функция используется для удаления из файла всех пиров
// т.к. в таком случае можно исключить повторно добавление одного ip
// и легко удалять ip с использованием wg-quick set
static void modifyConfigFile(const std::string& filename) {
    std::ifstream inFile(filename);
    std::ofstream outFile("temp.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Failed to open input or output file." << std::endl;
        return;
    }

    std::string line;
    bool foundPostDown = false;

    while (std::getline(inFile, line)) {
        if (line.find("PostDown = iptables -D FORWARD -i %i -j ACCEPT; iptables -t nat -D POSTROUTING -o $(ip a | grep -oP '(?<=2: ).*' | grep -o '^....') -j MASQUERADE") != std::string::npos) {
            foundPostDown = true;
            outFile << line << std::endl;
            break;
        }
        outFile << line << std::endl;
    }

    if (!foundPostDown) {
        std::cerr << "Specified line not found in the configuration file." << std::endl;
        inFile.close();
        outFile.close();
        return;
    }

    while (std::getline(inFile, line)) {
        // Skip
    }

    inFile.close();
    outFile.close();

    std::ifstream tempFile("temp.txt");
    std::ofstream configFile(filename);

    if (!tempFile.is_open() || !configFile.is_open()) {
        std::cerr << "Failed to open temporary or config file." << std::endl;
        return;
    }

    while (std::getline(tempFile, line)) {
        configFile << line << std::endl;
    }

    tempFile.close();
    configFile.close();
    std::remove("temp.txt");

    std::cout << "Configuration file modified successfully." << std::endl;
}


static bool isValidWireguardKey(std::string keyStr) {
    // Удалить пробельные символы из строки
    keyStr.erase(std::remove(keyStr.begin(), keyStr.end(), ' '), keyStr.end());
    keyStr.erase(std::remove(keyStr.begin(), keyStr.end(), '\n'), keyStr.end());

    // Проверяем, что ключевая строка имеет правильную длину
    if (keyStr.length() != 44) {
        return false;
    }

    // Проверяем, что ключевая строка содержит только допустимые символы Base64
    std::regex base64regex("[A-Za-z0-9+/]+={0,2}");
    if (!std::regex_match(keyStr, base64regex)) {
        return false;
    }

    // ключ валидный
    return true;
}

std::vector<WireguardPeer> parseWireGuardShowOutput(const std::string& output) {
    std::vector<WireguardPeer> peers;
    std::istringstream stream(output);
    std::string line;

    while (std::getline(stream, line)) {
        if (line.find("peer:") != std::string::npos) {
            WireguardPeer peer;
            std::istringstream public_key(line);
            public_key.ignore(6);
            public_key >> peer.publicKey;

            // Extract allowed IPs
            std::getline(stream, line);
            std::istringstream ipsStream(line);
            ipsStream.ignore(15); // Skip "  allowed ips: "
            std::getline(ipsStream, peer.allowedIPs, ',');

            peers.push_back(peer);
        }
    }

    return peers;
}

// получение вывода при вводе команды в командную строку
static std::string executeCommand(const std::string& command) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(command.c_str(), "r"), pclose);

    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }

    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }

    return result;
}

// используется для проверки уже созданного конфига на валидность
// static bool isConfigValid(const std::string& configPath) {
//     std::string command = "sudo wg-quick up " + configPath;
//     std::cout << "error" << std::endl;
//     int result = system(command.c_str());
//     // закрываем конфиг
//     std::string commandClose = "sudo wg-quick down" + configPath;
//     system(commandClose.c_str());
//     return result == 0;
// }

Config::Config(const std::string& name_) : name(name_) {
    createKey();
    makeConfig(name_);
}

void Config::run() {
    std::string command = "sudo wg-quick up " + name;
    if (system(command.c_str()) == -1) {
        throw std::runtime_error("WireGuard startup error");
    }
    modifyConfigFile(name);
}

void Config::stop() {
    // перед остановкой нужно сохранить всех новых peer в кофиг
    std::string commandInfo = executeCommand("wg show");

    std::string command = "sudo wg-quick down " + name;
    system(command.c_str());

    std::vector<WireguardPeer> peers = parseWireGuardShowOutput(commandInfo);
    for (const auto& peer : peers) {
        AddPeerToConfig(peer);
    }
}

std::string Config::addPeer(std::string key) {
    if (isValidWireguardKey(key)) {
        std::string allowedIp = getAllowedIP();
        if (allowedIp == "ServerFull\n") {
            return allowedIp;
        }
        std::cout << "New peer! Ip " << allowedIp << std::endl;
        std::string command = "sudo wg set wg0 peer " + key +
                            " allowed-ips " + allowedIp;
        size_t a = system(command.c_str());
        std::string serverKey = getPublicKey() + " " + allowedIp + '\n';
        return serverKey;
    }
    std::string errorMessage = "KeyError";
    return errorMessage;
}

void Config::AddPeerToConfig(const WireguardPeer& peer) {
    std::ofstream configFile;
    configFile.open(name, std::ios_base::app);

    if (configFile.is_open()) {
        configFile << "\n[Peer]\n";
        configFile << "PublicKey = " << peer.publicKey << "\n";
        configFile << "AllowedIPs = " << peer.allowedIPs << "\n";
        configFile.close();
        std::cout << "WireGuard peer added successfully to the configuration file." << std::endl;
    } else {
        std::cerr << "Unable to open the configuration file.\n";
    }
}

std::string Config::getAllowedIP() {
    auto it = ipPull.begin();
    std::string firstValue;
    if (it != ipPull.end()) {
        firstValue = it->second;
        ipPull.erase(it);
    } else {
        // в данном случае мы отдали все ip, нужно найти peer
        // с самым большим handshake и удалить его из интерфейса
        // передав его ip входящему
        // получаем самый большой latest handshake
        std::string info = executeCommand("wg show | tail 5");
        std::string peer;
        std::string ips;
        if (isPeerLatestHadshake(info, peer, ips)) {
            std::string command = "wg set wg0 peer " + peer + " remove";
            system(command.c_str());
            ipPull.insert(std::make_pair(std::stoull(extractIPValue(ips)), ips));
            firstValue = ips;
        } else {
            firstValue = "ServerFull\n";
        }
        // To Do
        // нужно найти конфиг самым больших last handshake соединением
        // удалить его с помощью wg set выдать его ip адрес новому peer
    }
    return firstValue;
}

void Config::createKey() {
    std::string pathPublicKey = defaultPath + "publickey";
    std::string pathPrivateKey = defaultPath + "privatekey";
    // если ключи уже были созданы просто считаем их
    if (std::filesystem::exists(pathPublicKey) &&
        std::filesystem::exists(pathPrivateKey))   
    {
        std::ifstream publicKeyFile(pathPublicKey);
        std::ifstream privateKeyFile(pathPrivateKey);
        if (publicKeyFile.is_open() && privateKeyFile.is_open()) {
            std::getline(publicKeyFile, publicKey);
            std::getline(privateKeyFile, privateKey);
            publicKeyFile.close();
            privateKeyFile.close();
        }

    } else {
        std::string command = "wg genkey | tee " + pathPrivateKey +
                              " | wg pubkey > " + pathPublicKey;
        std::system(command.c_str());
        std::ifstream publicKeyFile(pathPublicKey);
        std::ifstream privateKeyFile(pathPrivateKey);
        if (publicKeyFile.is_open() && privateKeyFile.is_open()) {
            std::getline(publicKeyFile, publicKey);
            std::getline(privateKeyFile, privateKey);
            publicKeyFile.close();
            privateKeyFile.close();
        }
    }
}

void Config::makeConfig(const std::string& path) {
    // заполняем значения ip для peer's
    std::string ipTest = "10.20.0.";

    // пока будут доступны от 101 - 255
    // после тестирование можно увеличить до 2 - 255
    for (size_t i = 101; i < 255; i ++) {
        ipPull[i] = ipTest + std::to_string(i) + "/32";
    }

    // поверка на существования уже созданного конфига
    if (std::filesystem::exists(path)) {
        std::cout << "Config file already exists" << std::endl;
        loadFromFile(path);

    } else {
        // удаляем файл если он уже был создан
        std::remove(path.c_str());

        std::ofstream outputFile(path); // создаем файл wireguard.conf

        // заполняем файл содержимым
        outputFile << "[Interface]\n";
        outputFile << "Address = " + defaultIpServer + "\n";
        outputFile << "Listenport = " + defaultPort + "\n";
        outputFile << "Privatekey = " + privateKey + "\n";
        outputFile << "PostUp = " + defaultPostUp + "\n";
        outputFile << "PostDown = " + defaultPostDown + "\n";
        outputFile << "\n";

        outputFile.close();
    }
}

void Config::deleteConfig(const std::string& path) {
    if (std::remove(path.c_str()) != 0) {
        std::cout << "Error deleted" << std::endl;
    } else {
        std::cout << "File delete" << std::endl;
    }
}

void Config::loadFromFile(const std::string& path) {
    std::ifstream file(path);

    std::string line;
    bool isInterfaceSection = false;
    bool isPeerSection = false;
    while (std::getline(file, line)) {
        // пропускает пустую или строку с комментариями
        if (line.empty() || line[0] == '#') {
            continue;
        }

        if ((line.find("[Interface]")) != std::string::npos) {
            isInterfaceSection = true;
            isPeerSection = false;
            continue;
        } else if (line.find("[Peer]") != std::string::npos) {
            isInterfaceSection = false;
            isPeerSection = true;
            ++peer;
            continue;
        }

        std::istringstream iss(line);
        std::string key, value;
        std::getline(iss, key, '=');
        std::getline(iss, value);

        value.substr(value.find_first_not_of(' '));
        key = key.substr(0, key.find_last_not_of(' ') + 1);

        // считывает основные данные из cегмента Interface
        if (isInterfaceSection) {
            if (key == "Listenport") {
                port = std::stoi(value);
            }

        // считывает основные данные из сегмента Peer
        } else if (isPeerSection) {
            // найденные значение peer (уже записанные)
            // удаляем из ipPull
            if (key == "AllowedIPs") {
                parseIpForSearch(value);
                size_t findValue = std::stoull(value);
                auto it = ipPull.find(findValue);
                if (it != ipPull.end()) {
                    ipPull.erase(it);
                }
            }
        }
    }
}

std::string Config::getPublicKey() {
    return publicKey;
}