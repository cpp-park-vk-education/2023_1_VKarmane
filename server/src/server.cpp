#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <unordered_map>
#include "config.hpp"
#include "server.hpp"
#include "VpnWorker.hpp"

using boost::asio::ip::tcp;

void Server::run() {
        accept();
    }

void Server::accept() {
    tcp::socket socket(acceptor_.get_executor());
    acceptor_.async_accept(socket, [this, &socket](const boost::system::error_code& error) {
        if (!error) {
            std::string client_ip_address = socket.remote_endpoint().address().to_string();
            std::shared_ptr<VpnWorker> worker = std::make_shared<VpnWorker>(std::move(socket), config_);
            worker->run();
        }
        accept();
    });
}
