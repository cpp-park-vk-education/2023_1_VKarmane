#include <gtest/gtest.h>
#include "ConfigClient.hpp"

// Тестирование конструктора ConfigClient с параметрами
TEST(ConfigClientTest, ParameterizedConstructor) {
  std::string name = "client1";
  std::string configname = "invalid_config.txt";

  ConfigClient client(name, configname);

  // Проверка значений, установленных из параметров
  EXPECT_EQ(name, client._name);
  EXPECT_EQ("", client.interfaceData.address);
  EXPECT_EQ("", client.interfaceData.privateKey);
  EXPECT_EQ("", client.peerData.publicKey);
  EXPECT_EQ("23.23.23.23", client.peerData.endpoint);
  EXPECT_EQ(0, client.peerData.persistentKeepalive);
  EXPECT_EQ("", client._publicKeyClient); // Значение будет установлено позже в методе genPair()
  EXPECT_EQ(0, client.interfaceData.dnsServers.size());
  EXPECT_EQ(2, client.peerData.allowedIPs.size());
}

// Тестирование метода genPair()
TEST(ConfigClientTest, GenPair) {
  ConfigClient client;

  // Проверка, что ключи не установлены до вызова метода genPair()
  EXPECT_EQ("", client._publicKeyClient);
  EXPECT_EQ("", client.interfaceData.privateKey);

  client.genPair();

  // Проверка, что ключи установлены после вызова метода genPair()
  EXPECT_NE("", client._publicKeyClient);
  EXPECT_NE("", client.interfaceData.privateKey);
}


// Тестирование метода buildConfig()
TEST(ConfigClientTest, BuildConfig) {
  ConfigClient client;
  client._name = "client1";
  client.interfaceData.address = "address1";
  client.interfaceData.privateKey = "privateKey1";
  client.peerData.publicKey = "publicKey1";
  client.peerData.endpoint = "endpoint1";
  client.interfaceData.dnsServers = {"dns1", "dns2"};
  client.peerData.allowedIPs = {"ip1", "ip2"};

  // Вызов тестируемого метода
  client.buildConfig();

  std::ifstream configFile("client1.conf");
  std::string content((std::istreambuf_iterator<char>(configFile)),
                       std::istreambuf_iterator<char>());
  EXPECT_EQ(expectedContent, content);
}

// Тестирование метода changeAllowedIPs()
TEST(ConfigClientTest, ChangeAllowedIPs) {
  ConfigClient client;
  client._name = "client1";
  client.interfaceData.address = "address1";
  client.interfaceData.privateKey = "privateKey1";
  client.peerData.publicKey = "publicKey1";
  client.peerData.endpoint = "endpoint1";
  client.interfaceData.dnsServers = {"dns1", "dns2"};
  client.peerData.allowedIPs = {"ip1", "ip2"};

  std::string newAllowed = "newAllowed.conf";

  // Вызов тестируемого метода
  client.changeAllowedIPs(newAllowed);

  std::ifstream configFile("client1.conf");
  std::string content((std::istreambuf_iterator<char>(configFile)),
                       std::istreambuf_iterator<char>());
  EXPECT_EQ(expectedContent, content);
}

// Тестирование метода setUnspecified()
TEST(ConfigClientTest, SetUnspecified) {
  ConfigClient client;

  // Вызов тестируемого метода
  client.setUnspecified();

  // Проверка изменений в объекте client
  EXPECT_EQ(2, client.peerData.allowedIPs.size());
  EXPECT_EQ("8.8.8.8", client.interfaceData.dnsServers[0]);
  EXPECT_EQ("8.8.4.4", client.interfaceData.dnsServers[1]);
  EXPECT_EQ(25, client.peerData.persistentKeepalive);
  
}

// Тестирование метода operator=()
TEST(ConfigClientTest, AssignmentOperator) {
  ConfigClient client1;
  ConfigClient client2;
  client1._name = "client1";
  client1.interfaceData.address = "address1";
  client1.interfaceData.privateKey = "privateKey1";
  client1.peerData.publicKey = "publicKey1";
  client1.peerData.endpoint = "endpoint1";
  client1.interfaceData.dnsServers = {"dns1", "dns2"};
  client1.peerData.allowedIPs = {"ip1", "ip2"};

  // Вызов тестируемого метода
  client2 = client1;

  // Проверка, что объект client2 стал копией объекта client1
  
  EXPECT_EQ(client1._name, client2._name);
  EXPECT_EQ(client1.interfaceData.address, client2.interfaceData.address);
  EXPECT_EQ(client1.interfaceData.privateKey, client2.interfaceData.privateKey);
  EXPECT_EQ(client1.peerData.publicKey, client2.peerData.publicKey);
  EXPECT_EQ(client1.peerData.endpoint, client2.peerData.endpoint);
  EXPECT_EQ(client1.interfaceData.dnsServers, client2.interfaceData.dnsServers);
  EXPECT_EQ(client1.peerData.allowedIPs, client2.peerData.allowedIPs);
}

// Тестирование метода genPair()
TEST(ConfigClientTest, GenPair) {
  ConfigClient client;

  // Вызов тестируемого метода
  client.genPair();

  // Проверка изменений в объекте client
  EXPECT_FALSE(client._publicKeyClient.empty());
  EXPECT_FALSE(client.interfaceData.privateKey.empty());
}

// Тестирование метода ConfigClient()
TEST(ConfigClientTest, Constructor) {
  // Создание объекта с использованием конструктора
  ConfigClient client;

  // Проверка значений полей объекта client
  EXPECT_EQ("", client._name);
  EXPECT_EQ("", client.interfaceData.address);
  EXPECT_EQ("", client.interfaceData.privateKey);
  EXPECT_EQ("", client.peerData.publicKey);
  EXPECT_EQ("", client.peerData.endpoint);
  EXPECT_TRUE(client.interfaceData.dnsServers.empty());
  EXPECT_TRUE(client.peerData.allowedIPs.empty());
}
