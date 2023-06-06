#include <gtest/gtest.h>
#include <fstream>
#include <filesystem>
#include "config.hpp"

// проверка на создания конфига и корректность работы его методов
TEST(WireGuardConfigTest, BasicConfigCreateTest) {
    Config config("/etc/wireguard/wg0.conf");
    config.run();

    // Проверяем, что конфигурация WireGuard успешно поднята
    std::string command = "wg show wg0";
    int result = system(command.c_str());
    ASSERT_EQ(result, 0);
    config.stop();
}

// проверка на удаление конфига
TEST(WireGuardConfigTest, BasicConfigDeleteTest) {
    std::string dir = "/etc/wireguard/";
    std::string nameFile = dir + "wg0.conf";
    Config config(nameFile);

    config.deleteConfig(nameFile);
    ASSERT_TRUE(!std::filesystem::exists(nameFile));
}

// проверка на возвращения ответа на валидный запрос
TEST(WireGuardConfigTest, answerServerTest) {
    std::string dir = "/etc/wireguard/";
    std::string nameFile = dir + "wg0.conf";
    Config config(nameFile);
    config.run();

    std::string validKey = "YPoBXTvrm+slM3dyKsyY9pYwm4Z9dHoD71BG1VPAslU=";
    std::string answer = config.addPeer(validKey);
    WireguardKey key;

    std::string validResponce = key.getPulicKey() + " 10.20.0.101/32" +  "\n";
    ASSERT_TRUE(answer == validResponce);
    config.stop();
    config.deleteConfig(nameFile);
}

// проверка на возвращения ответа на невалидный запрос
TEST(WireGuardConfigTest, answerNotValidKeyTest) {
    std::string dir = "/etc/wireguard/";
    std::string nameFile = dir + "wg0.conf";
    Config config(nameFile);
    config.run();

    std::string validKey = "Error";
    std::string answer = config.addPeer(validKey);

    ASSERT_TRUE(answer == "KeyError");
    config.stop();
    config.deleteConfig(nameFile);
}

// проверка на создания файлов с ключами
TEST(WireGuardKey, GenerateKeyTest) {
    std::string dir = "/etc/wireguard/";
    std::string publicKeyFile = dir + "publickey";
    std::string privateKeyFile = dir + "privatekey";

    // если ключи уже были созданы удаляем
    std::filesystem::remove(publicKeyFile);
    std::filesystem::remove(privateKeyFile);

    WireguardKey key;
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
}
