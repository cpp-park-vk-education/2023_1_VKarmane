// Copyright 2023 Kosmatoff
#pragma once

#include <vector>
#include <unordered_map>
#include <string>

class ICongif {
 public:
    virtual void makeConfig(const std::string& name) = 0;
    virtual void deleteConfig(const std::string& name) = 0;
};

class Config : public ICongif {
 public:
    // В конструктор передается имя файла с путем до него dir + name
    // Рекомендуется делать dir: "/etc/wireguard/"
    explicit Config(const std::string& name_) { makeConfig(name_); }
    ~Config();

    // запускает wg-quick up
    void run();  // try ...

    // отключает wg-quick down
    void stop();

    void makeConfig(const std::string& name) override;
    void deleteConfig(const std::string& name) override;
    void changeConfig();

    // проверяет запущен ли конфиг
    bool checkConfig();

    std::string& addPeer(std::string key);

    void setListenPort(int port_);
    void createKey();

    std::string& getPublicKey();

 private:
    std::string name;
    int peer;
    int port;
    std::string publicKey;
    std::vector<std::string> ipull;
};
