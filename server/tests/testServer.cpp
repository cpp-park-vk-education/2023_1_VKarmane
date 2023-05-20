#include <gtest/gtest.h>

#include "server.hpp"
#include "VpnWorker.hpp"

using boost::asio::io_service;
using boost::asio::ip::tcp;

TEST(ServerTest, Run) {
    boost::asio::io_context io_context;
    std::string dir = "/etc/wireguard/";
    Config config(dir + "wg0.conf");
    unsigned short port = 1234;
    std::string ipServer = "127.0.0.1";
    Server server(io_context, port, config, ipServer);
    EXPECT_NO_THROW();
}

// TEST(ServerTest, InvalidPort) {
//     boost::asio::io_service io_service;
//     std::string dir = "/etc/wireguard/";
//     Config config(dir + "wg0.conf");
//     unsigned int port = 0;
//     EXPECT_THROW(Server server(io_service, config, port), std::exception);
// }

// TEST(ServerTest, InvalidPortBig) {
//     boost::asio::io_service io_service;
//     std::string dir = "/etc/wireguard/";
//     Config config(dir + "wg0.conf");
//     unsigned int port = 100000;  // Неправильный порт
//     EXPECT_THROW(Server server(io_service, config, port), std::exception);
// }

// TEST(ServerTest, InvalidPortSmall) {
//     boost::asio::io_service io_service;
//     std::string dir = "/etc/wireguard/";
//     Config config(dir + "wg0.conf");
//     unsigned int port = 0;
//     EXPECT_THROW(Server server(io_service, config, port), std::exception);
// }


