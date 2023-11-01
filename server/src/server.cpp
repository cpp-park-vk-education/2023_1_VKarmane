// Copyright 2023 Kosmatoff

#include <iostream>

#include "server.hpp"

using boost::asio::ip::tcp;

Server::Server(boost::asio::io_context& io_context, unsigned short port, Config& config, std::string& address)
    : _io_context(io_context),
        _acceptor(io_context, tcp::endpoint(boost::asio::ip::address::from_string(address), port)),
        _config(config) {

    std::cout << "Server is now running on port " << port << "\n";
    doAccept();
}

Server::~Server() {
    Cleanup();
}

void Server::doAccept() {
    // Create a new session object
    auto session = std::make_shared<VpnWorker>(_io_context, _config);

    // Start an asynchronous accept operation.
    _acceptor.async_accept(session->socket(),
                          [this, session](boost::system::error_code ec) {
                                if (!ec) {
                                    session->start();
                                }
                                doAccept();
                            });
}

void Server::Cleanup() {
    std::cout << "Performing cleanup..." << std::endl;

    _acceptor.close();

    _io_context.stop();
}
