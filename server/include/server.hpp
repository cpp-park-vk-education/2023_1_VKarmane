// Copyright 2023 Kosmatoff
#pragma once

#include <boost>
#include <memory>

class IServer {
 public:
    virtual void run() = 0;
    virtual void stop() = 0;
 private:
    virtual handle_accept(std::shared_ptr<boost::asio::ip::tcp::socket> socket,
                          const boost::system::error_code& error) = 0;
};

class Server: public IServer {
 public:
    void run() override;
    void stop() override;
 private:
    void handle_accept(std::shared_ptr<boost::asio::ip::tcp::socket> socket,
                          const boost::system::error_code& error) override
};