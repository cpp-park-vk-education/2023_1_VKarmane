// Copyright 2023 Kosmatoff
#pragma once

#include <boost/asio.hpp>
#include <string>
#include <unordered_map>

#include "VpnWorker.hpp"
#include "config.hpp"

using boost::asio::ip::tcp;

class Server {
 public:
    Server(boost::asio::io_context& io_context, unsigned short port, Config& config, std::string& address);

 private:
    void doAccept();

    boost::asio::io_context& _io_context;
    boost::asio::ip::tcp::acceptor _acceptor;
    Config& _config;
};