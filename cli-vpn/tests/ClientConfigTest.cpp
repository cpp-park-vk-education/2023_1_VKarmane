#include <gtest/gtest.h>
#include "ConfigClient.hpp"

(ConfigClientTest, CreateConfigClient) {
    ConfigClient config("name", "configname");

    ASSERT_EQ(config.getPrivateKey(), "");
    ASSERT_EQ(config.getPublicKey(), "");
    ASSERT_EQ(config.ipPublicKeyrequest(), 0);
}

TEST(ConfigClientTest, SettersAndGetters) {
    ConfigClient config;

    config.setAddress("10.0.0.1");
    ASSERT_EQ(config.getAddress(), "10.0.0.1");

    config.setPrivateKey("private_key");
    ASSERT_EQ(config.getPrivateKey(), "private_key");

    config.setDns({"8.8.8.8"});
    ASSERT_EQ(config.getDnsList(), std::vector<std::string>{"8.8.8.8"});

    config.setPublicKey("public_key");
    ASSERT_EQ(config.getPublicKey(), "public_key");

    config.setAllowedIPs({"10.0.0.2"});
    ASSERT_EQ(config.getAllowedIPs(), std::vector<std::string>{"10.0.0.2"});

    config.setEndpoint("10.0.0.1:51820");
    ASSERT_EQ(config.getEndpoint(), "10.0.0.1:51820");

    config.setKeepAlive(5);
    ASSERT_EQ(config.getKeepAlive(), 5);
}

TEST(ConfigClientTest, BuildAndChangeConfig) {
    ConfigClient config;

    config.setAddress("10.0.0.1");
    config.setPrivateKey("private_key");
    config.setPublicKey("public_key");
    config.setAllowedIPs({"10.0.0.2"});
    config.setEndpoint("10.0.0.1:51820");
    config.setKeepAlive(5);

    config.buildConfig();

    std::ifstream file("wg.conf");
    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string configContent = buffer.str();

    ASSERT_TRUE(configContent.find("Address = 10.0.0.1") != std::string::npos);
    ASSERT_TRUE(configContent.find("PrivateKey = private_key") != std::string::npos);
    ASSERT_TRUE(configContent.find("ListenPort = 51820") != std::string::npos);
    ASSERT_TRUE(configContent.find("PublicKey = public_key") != std::string::npos);
    ASSERT_TRUE(configContent.find("AllowedIPs = 10.0.0.2") != std::string::npos);

    config.setAllowedIPs({"10.0.0.3"});
    config.setEndpoint("10.0.0.2:41920");
    config.setKeepAlive(10);

    config.changeConfig();

    std::ifstream newFile("wg.conf");
    std::stringstream newBuffer;
    newBuffer << newFile.rdbuf();
    std::string newConfigContent = newBuffer.str();

    ASSERT_TRUE(newConfigContent.find("Address = 10.0.0.1") != std::string::npos);
    ASSERT_TRUE(newConfigContent.find("PrivateKey = private_key") != std::string::npos);
    ASSERT_TRUE(newConfigContent.find("ListenPort = 41920") != std::string::npos);
    ASSERT_TRUE(newConfigContent.find("PublicKey = public_key") != std::string::npos);
    ASSERT_TRUE(newConfigContent.find("AllowedIPs = 10.0.0.3") != std::string::npos);
}