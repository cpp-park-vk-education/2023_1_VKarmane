// Copyright 2023 Kosmatoff
#pragma once

#include <memory>
#include <boost>
#include "config.hpp"
#include <string>

class IVpnWorker {
 public:
    virtual void handle_request(std::shared_ptr<boost::asio::ip::tcp::socket> socket);
};

class VpnWorker : public IVpnWorker {
 public:
    void handle_request(std::shared_ptr<boost::asio::ip::tcp::socket> socket) override;
    std::string generate_public();
    void add_client_to_config();
    void get_available_ip_address();
 private:
    Config config;
};

