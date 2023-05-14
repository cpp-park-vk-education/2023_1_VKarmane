#pragma once

#include <mutex>
#include <boost/asio.hpp>

#include "config.hpp"

using boost::asio::ip::tcp;

class VpnWorker {
 public:
    VpnWorker(tcp::socket&& socket, Config& config)
        : socket_(std::move(socket)), config_(config) {}

    void run();

 private:
    tcp::socket socket_;
    Config& config_;
    std::mutex config_mutex_;
};