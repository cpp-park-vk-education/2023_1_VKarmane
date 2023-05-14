#pragma once

#include "VpnWorker.hpp"

#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <memory>

// using boost_error = const boost::system::error_code;
static inline constexpr int default_port = 2020;

class Server {
 public:
    Server(boost::asio::io_context &context, unsigned int port = default_port);

    void start();

 private:
    void acceptConnection();

    void handleConnection(std::shared_ptr<VpnWorker> newVpnConnection,
                          const boost::system::error_code &error);

    boost::asio::io_context &io_context_;
    boost::asio::ip::tcp::acceptor acceptor_;
};