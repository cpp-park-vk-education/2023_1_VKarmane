#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "server.hpp"
#include "config.hpp"
#include "VpnWorker.hpp"

using boost::asio::io_service;
using boost::asio::ip::tcp;
using testing::_;
using testing::Return;

// ============================GMock=================================


// ============================GMock=================================

TEST(ServerTest, Run) {
    boost::asio::io_service io_service;
    std::string dir = "/etc/wireguard/";
    Config config(dir + "wg0.conf");
    unsigned int port = 1234;
    Server server(io_service, config, port);
    EXPECT_NO_THROW(server.run());
}

TEST(ServerTest, InvalidPort) {
    boost::asio::io_service io_service;
    std::string dir = "/etc/wireguard/";
    Config config(dir + "wg0.conf");
    unsigned int port = 0;
    EXPECT_THROW(Server server(io_service, config, port), std::exception);
}

TEST(ServerTest, InvalidPortBig) {
    boost::asio::io_service io_service;
    std::string dir = "/etc/wireguard/";
    Config config(dir + "wg0.conf");
    unsigned int port = 100000;  // Неправильный порт
    EXPECT_THROW(Server server(io_service, config, port), std::exception);
}

TEST(ServerTest, InvalidPortSmall) {
    boost::asio::io_service io_service;
    std::string dir = "/etc/wireguard/";
    Config config(dir + "wg0.conf");
    unsigned int port = 0;
    EXPECT_THROW(Server server(io_service, config, port), std::exception);
}
