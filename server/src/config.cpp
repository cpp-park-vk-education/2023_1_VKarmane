// Copyright 2023 Kosmatoff

#include <filesystem>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

#include "../include/config.hpp"

static const std::string defaultIpServer = "10.20.0.1/24";
static const std::string defaultPort = "51285";
static const std::string defaultPath = "/etc/wireguard/";
static const std::string defaultPostUp = "iptables -A FORWARD -i %i -j ACCEPT; iptables -t nat -A POSTROUTING -o $(ip a | grep -oP '(?<=2: ).*' | grep -o '^....') -j MASQUERADE";
static const std::string defaultPostDown = "iptables -D FORWARD -i %i -j ACCEPT; iptables -t nat -D POSTROUTING -o $(ip a | grep -oP '(?<=2: ).*' | grep -o '^....') -j MASQUERADE";

static void parseIpForSearch(std::string& ip) {
    std::size_t pos = ip.find_last_of(".");
    ip = ip.substr(pos + 1); // output "101"
}

// используется для проверки уже созданного конфига на валидность
static bool isConfigValid(const std::string& configPath) {
    std::string command = "sudo wg-quick up " + configPath;
    int result = system(command.c_str());
    // закрываем конфиг
    std::string commandClose = "sudo wg-quick down" + configPath;
    system(commandClose.c_str());
    return result == 0;
}

Config::Config(const std::string& name_) : name(name_) {
    createKey();
    makeConfig(name_);
}

void Config::run() {
    std::string command = "sudo wg-quick up " + name;
    if (system(command.c_str()) == -1) {
        throw std::runtime_error("WireGuard startup error");
    }
}

Config::~Config() {
    stop();
}

void Config::stop() {
    std::string command = "sudo wg-quick down " + name;
}

std::string& Config::addPeer(std::string key) {
    std::string allowedIp = getAllowedIP();
    std::string command = "sudo wg set wg0 peer " + key +
                          " allowed-ips " + allowedIp;
    system(command.c_str());
    std::string serverKey = getPublicKey();
    return serverKey;
}

std::string& Config::getAllowedIP() {
    auto it = ipPull.begin();
    std::string firstValue;
    if (it != ipPull.end()) {
        std::string firstValue = it->second;
        ipPull.erase(it);
    } else {
        // TO DO
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
    if (std::filesystem::exists(path) && isConfigValid(path)) {
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
                auto it = ipPull.find(static_cast<size_t>(findValue));
                if (it != ipPull.end()) {
                    ipPull.erase(it);
                }
            }
        }
    }
}

const std::string& Config::getPublicKey() {
    return publicKey;
}