// Copyright 2023 Kosmatoff
#pragma once

//#include <mutex>
#include <boost/asio.hpp>

#include "config.hpp"

using boost::asio::ip::tcp;

class VpnWorker : public std::enable_shared_from_this<VpnWorker> {
 public:
    VpnWorker(boost::asio::io_context& io_context, Config& config)
        : _socket(io_context),
          _config(config) {}
    boost::asio::ip::tcp::socket& socket();

    void start();

 private:
    void doRead();

    void doWrite();

    static constexpr std::size_t max_length = 1024;
    boost::asio::ip::tcp::socket _socket;
    char _data[max_length]{};
    std::string ipAddPeer;
    Config& _config;
};