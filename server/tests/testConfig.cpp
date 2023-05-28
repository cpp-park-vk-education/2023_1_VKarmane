#include <gtest/gtest.h>
#include "config.hpp"
#include <fstream>
#include <filesystem>

// проверка на создания конфига c пирами и корректность работы его методов
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

// ===========================================================================

// // проверка на создания файлов с ключами
// TEST(WireGuardGenerateKeyTest, GenerateKeyTest) {
//     std::string dir = "/etc/wireguard/";
//     std::string publicKeyFile = dir + "publickey";
//     std::string privateKeyFile = dir + "privatekey";

//     // если ключи уже были созданы удаляем
//     std::filesystem::remove(publicKeyFile);
//     std::filesystem::remove(privateKeyFile);

//     Config config(dir + "wg0.conf");

//     // проверяем, что файлы уже созданы
//     ASSERT_TRUE(std::filesystem::exists(publicKeyFile));
//     ASSERT_TRUE(std::filesystem::exists(privateKeyFile));

//     // Проверяем, что файлы не пустые
//     std::ifstream publicKeyStream(publicKeyFile);
//     std::ifstream privateKeyStream(privateKeyFile);
//     std::string public_key((std::istreambuf_iterator<char>(publicKeyStream)),
//                        std::istreambuf_iterator<char>());
//     std::string private_key((std::istreambuf_iterator<char>(privateKeyStream)),
//                         std::istreambuf_iterator<char>());
//     ASSERT_FALSE(public_key.empty());
//     ASSERT_FALSE(private_key.empty());

//     std::filesystem::remove(publicKeyFile);
//     std::filesystem::remove(privateKeyFile);
// }

// TEST(WireGuardConfigTest, AddPeer) {
//     std::string dir = "/etc/wireguard/";
//     Config config(dir + "wg0.conf");
//     config.run();
//     std::string ipPublic = config.addPeer("ALHo1Ji3W7quFYQKXgqVRA+QzgNRz3PrOk7/UeLdtm8=");
//     config.getPublicKey();
//     std::string testString = config.getPublicKey() + " 10.20.0.101/32\n";
//     ASSERT_EQ(ipPublic, testString);
//     config.stop();
// }