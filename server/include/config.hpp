// Copyright 2023 Kosmatoff
#pragma once

#include <map>
#include <string>
#include "wireguardKey.hpp"

struct WireguardPeer {
    std::string publicKey;
    std::string allowedIPs;
};

class ICongif {
 public:
    ~ICongif() = default;
    virtual void deleteConfig(const std::string& name) = 0;
 private:
    virtual void makeConfig(const std::string& path) = 0;
};

class Config : public ICongif {
 public:
    // В конструктор передается имя файла
    // Путь до файла рекомендуется указывать "etc/wireguard/name"
    explicit Config(const std::string& name_);
    ~Config();

    // запускает wg-quick up
    void run();  // try ...

    // отключает wg-quick down
    void stop();

    void deleteConfig(const std::string& name) override;

    std::string addPeer(const std::string& key);

 private:
    // создает рабочий конфиг wireguard и считывает данные
    // если конфиг уже существует, просто считывает данные
    void makeConfig(const std::string& name) override;

    void AddPeerToConfig(const WireguardPeer& peer);

    // вызывается, когда конфиг уже существует
    // считывает из него данные
    void loadFromFile(const std::string& path);

    // возвращает первый свободный ip по порядку и удаляет его из ipPull
    std::string getAllowedIP();

    std::string name;
    size_t peer = 101;
    int port;
    WireguardKey key;

    // хранит свободные ip от 101 - 255, которые выдаются клиенту
    std::map<std::size_t, std::string> ipPull;
};
