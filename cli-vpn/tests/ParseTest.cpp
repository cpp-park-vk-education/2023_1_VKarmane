#include <gtest/gtest.h>
#include "Parser.hpp"

TEST(ParseFileTest, isValidTest) {
     ParseFile parser;
     // Testing a valid config file
     EXPECT_TRUE(parser.isValid("../tests/test1.conf"));
     // Testing an invalid config file
     EXPECT_FALSE(parser.isValid("../tests/test2.conf"));
}

TEST(ParseFileTest, parseConfigTest) {
     ParseFile parser;
     // Testing a valid config file
     std::vector<std::vector<std::string>> output1 = parser.parseConfig("../tests/test1.conf");
     EXPECT_EQ(output1[0][0], "PrivateKey");
     EXPECT_EQ(output1[0][1], "ABC123");
     EXPECT_EQ(output1[1][0], "Address");
     EXPECT_EQ(output1[1][1], "10.0.0.1/24");
     EXPECT_EQ(output1[2][0], "DNS");
     EXPECT_EQ(output1[2][1], "8.8.8.8");
     EXPECT_EQ(output1[2][2], "8.8.4.4");
     EXPECT_EQ(output1[3][0], "PublicKey");
     EXPECT_EQ(output1[3][1], "A1B2C3D4E5F6G7H8I9J0K1L2M3N4O5P6Q7R8S9T0U");
     EXPECT_EQ(output1[4][0], "AllowedIPs");
     EXPECT_EQ(output1[4][1], "10.0.0.2/32");
     EXPECT_EQ(output1[4][2], "10.0.0.3/32");
     EXPECT_EQ(output1[5][0], "Endpoint");
     EXPECT_EQ(output1[5][1], "123.45.67.89:51820");
     EXPECT_EQ(output1[6][0], "PersistentKeepalive");
     EXPECT_EQ(output1[6][1], "25");

     // Testing an invalid config file
     std::vector<std::vector<std::string>> output2 = parser.parseConfig("../tests/test2.conf");
     EXPECT_EQ(output2.size(), 0);
}

TEST(ParseFileTest, parseNotStructuredTest) {
     ParseFile parser;
     std::vector<std::vector<std::string>> output1 = parser.parseNotStructured("../tests/test3.conf");
     EXPECT_EQ(output1[0][0], "URLlist");
     EXPECT_EQ(output1[0][1], "example.com");
     EXPECT_EQ(output1[0][2], "test.com");
     EXPECT_EQ(output1[1][0], "Endpoint");
     EXPECT_EQ(output1[1][1], "123.45.67.89:51820");

     std::vector<std::vector<std::string>> output2 = parser.parseNotStructured("../tests/test4.conf");
     EXPECT_EQ(output2.size(), 0);
}