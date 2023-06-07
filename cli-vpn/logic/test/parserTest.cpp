#include "gtest/gtest.h"
#include "Parser.hpp"

TEST(ConfigParserTest, CheckValidConfigFile) {
    ConfigParser parser;
    ASSERT_TRUE(parser.checkConfigFile("valid_config.txt"));
}

TEST(ConfigParserTest, CheckInvalidConfigFile) {
    ConfigParser parser;
    ASSERT_FALSE(parser.checkConfigFile("invalid_config.txt"));
}

TEST(ConfigParserTest, ParseValidConfigFile) {
    ConfigParser parser;
    parser.parseFile("valid_config.txt");

    InterfaceData interfaceData = parser.getInterfaceData();
    PeerData peerData = parser.getPeerData();
    std::vector<std::string> allowedIPs = parser.getAllowedIPs();

    ASSERT_EQ(interfaceData.address, "192.168.0.1/32");
    ASSERT_EQ(interfaceData.privateKey, "AFdTcYYfVgy4F6XHApHDVp8R47gLtH7Klgl6RYu/r0I=");
    ASSERT_EQ(interfaceData.dnsServers.size(), 2);
    ASSERT_EQ(interfaceData.dnsServers[0], "8.8.8.8");
    ASSERT_EQ(interfaceData.dnsServers[1], "8.8.4.4");

    ASSERT_EQ(peerData.publicKey, "bx1cNgOO9j3iw1cEhyYhE5qiU43fuHg0Y4uwzsglxho=");
    
    ASSERT_EQ(peerData.allowedIPs.size(), 3);
    ASSERT_EQ(peerData.allowedIPs[0], "10.0.0.1/32");
    ASSERT_EQ(peerData.allowedIPs[1], "10.0.0.2/32");
    ASSERT_EQ(peerData.allowedIPs[2], "10.0.0.3/32");

    ASSERT_EQ(peerData.endpoint, "45.45.45.45:12345");
    ASSERT_EQ(peerData.persistentKeepalive, 15);
}

TEST(ConfigParserTest, ParseInvalidConfigFile) {
    ConfigParser parser;
    parser.parseFile("invalid_config.txt");

    InterfaceData interfaceData = parser.getInterfaceData();
    PeerData peerData = parser.getPeerData();
    std::vector<std::string> allowedIPs = parser.getAllowedIPs();

    ASSERT_EQ(interfaceData.address, "");
    ASSERT_EQ(interfaceData.privateKey, "");
    ASSERT_EQ(interfaceData.dnsServers.size(), 0);

    ASSERT_EQ(peerData.publicKey, "");
    ASSERT_EQ(peerData.allowedIPs.size(), 2);
    ASSERT_EQ(peerData.allowedIPs[0], "google.com");
    ASSERT_EQ(peerData.allowedIPs[1], "vk.com");
    ASSERT_EQ(peerData.endpoint, "23.23.23.23");
    ASSERT_EQ(peerData.persistentKeepalive, 0);

    ASSERT_EQ(allowedIPs.size(), 2);
}

TEST(ConfigParserTest, TrimString) {
    ConfigParser parser;

    std::string str1 = "   Hello, World!   ";
    parser.trim(str1);
    ASSERT_EQ(str1, "Hello, World!");

    std::string str2 = "  \t";
    parser.trim(str2);
    ASSERT_EQ(str2, "");

    std::string str3 = "NoSpaces";
    parser.trim(str3);
    ASSERT_EQ(str3, "NoSpaces");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
