#pragma once

#include <boost/asio.hpp>
#include <string>
#include <unordered_map>

#include "config.hpp"
#include "VpnWorker.hpp"

using boost::asio::ip::tcp;

class Server {
 public:
    Server(boost::asio::io_service& io_service, Config& config, unsigned int port)
        : acceptor_(io_service, tcp::endpoint(tcp::v4(), port)),
          config_(config) {}

    void run();

 private:
    void accept();

    tcp::acceptor acceptor_;
    Config& config_;
};
