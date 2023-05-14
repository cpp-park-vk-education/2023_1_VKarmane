#include <gtest/gtest.h>
#include "config.hpp"
#include <fstream>
#include <filesystem>

// проверка на создания конфига c пирами и корректность работы его методов
TEST(WireGuardConfigTest, BasicConfigCreateTest) {
    std::string dir = "/etc/wireguard/";
    Config config(dir + "wg0.conf");
    config.createKey();
    config.setListenPort(51820);

    config.addPeer("yKm7rYF7n0GtML9KvXYoyytzaqqh4vfRPXT7RjrcZCY=");

    ASSERT_TRUE(std::filesystem::exists(dir + "wg0.conf"));
    
    std::ifstream fileTest("config.conf");
    std::ifstream file(dir + "wg0.conf");
    std::string testContent((std::istreambuf_iterator<char>(fileTest)),
                               std::istreambuf_iterator<char>());

    std::string actualContent((std::istreambuf_iterator<char>(file)),
                               std::istreambuf_iterator<char>());
    ASSERT_EQ(testContent, actualContent);
    config.deleteConfig(dir + "wg0.conf");
    config.deleteConfig("config.conf");
}

// проверка на удаление конфига
TEST(WireGuardConfigTest, BasicConfigDeleteTest) {
    std::string dir = "/etc/wireguard/";
    std::string nameFile = dir + "wg0.conf";
    Config config(nameFile);

    config.deleteConfig(nameFile);
    ASSERT_TRUE(!std::filesystem::exists(nameFile));
}

// ===========================================================================

// проверка на создания файлов с ключами
TEST(WireGuardGenerateKeyTest, GenerateKeyTest) {
    std::string dir = "/etc/wireguard/";
    std::string publicKeyFile = dir + "publickey";
    std::string privateKeyFile = dir + "privatekey";

    // если ключи уже были созданы удаляем
    std::filesystem::remove(publicKeyFile);
    std::filesystem::remove(privateKeyFile);

    Config config("wg0.conf");
    config.createKey();

    // проверяем, что файлы уже созданы
    ASSERT_TRUE(std::filesystem::exists(publicKeyFile));
    ASSERT_TRUE(std::filesystem::exists(privateKeyFile));

    // Проверяем, что файлы не пустые
    std::ifstream publicKeyStream(publicKeyFile);
    std::ifstream privateKeyStream(privateKeyFile);
    std::string public_key((std::istreambuf_iterator<char>(publicKeyStream)),
                       std::istreambuf_iterator<char>());
    std::string private_key((std::istreambuf_iterator<char>(privateKeyStream)),
                        std::istreambuf_iterator<char>());
    ASSERT_FALSE(public_key.empty());
    ASSERT_FALSE(private_key.empty());

    std::filesystem::remove(publicKeyFile);
    std::filesystem::remove(privateKeyFile);
    config.deleteConfig("config.conf");
}

