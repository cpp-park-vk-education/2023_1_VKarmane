#include <filesystem>
#include <fstream>
#include <sstream>
#include <iostream>
#include <regex>

#include "../include/wireguardKey.hpp"

static const std::string defaultPath = "/etc/wireguard/";
static const std::string defaultPathPrivateKey = "/etc/wireguard/privatekey";
static const std::string defaultPathPublicKey = "/etc/wireguard/publickey";

WireguardKey::WireguardKey() {
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
        createKey();
    }
}
void WireguardKey::createKey() {
    std::string command = "wg genkey | tee " + defaultPathPrivateKey +
                            " | wg pubkey > " + defaultPathPublicKey;
    std::system(command.c_str());
    std::ifstream privateKeyFile(defaultPathPrivateKey);
    std::ifstream publicKeyFile(defaultPathPublicKey);
    if (publicKeyFile.is_open() && privateKeyFile.is_open()) {
        std::getline(publicKeyFile, publicKey);
        std::getline(privateKeyFile, privateKey);
        publicKeyFile.close();
        privateKeyFile.close();
    }
}

bool WireguardKey::isValidWireguardKey(const std::string& key) {
    // Проверяем, что ключевая строка имеет правильную длину
    if (key.length() != 44) {
        return false;
    }

    // Проверяем, что ключевая строка содержит только допустимые символы Base64
    std::regex base64regex("[A-Za-z0-9+/]+={0,2}");
    if (!std::regex_match(key, base64regex)) {
        return false;
    }

    // ключ валидный
    return true;
}


std::string WireguardKey::getPulicKey() {
    return publicKey;
}

std::string WireguardKey::getPrivateKey() {
    return privateKey;
}