// Copyright 2023 Kosmatoff
#include <iostream>
#include "VpnWorker.hpp"

void VpnWorker::run()  {
    std::lock_guard<std::mutex> lock(config_mutex_);

    std::string client_ip_address = socket_.remote_endpoint().address().to_string();
    boost::asio::streambuf buffer;
    boost::asio::async_read_until(socket_, buffer, '\n', [this, &client_ip_address, &buffer](const boost::system::error_code &error, size_t bytes_transferred) {        
        if (!error) {
            std::string public_key(boost::asio::buffers_begin(buffer.data()), boost::asio::buffers_end(buffer.data()) - 1);
            // запишет новый коннект в конфиг и вернет ipClient на сервере
            std::string ipClientOnServer = config_.addPeer(public_key);

            std::string message = "IP: " + ipClientOnServer + "\nPublic key: " + config_.getPublicKey() + "\n";
            boost::asio::async_write(socket_, boost::asio::buffer(message), [this](const boost::system::error_code& error, size_t bytes_transferred) {
                socket_.shutdown(tcp::socket::shutdown_both);
                socket_.close();
            });
        } else {
            std::cerr << "Error in async_read_until: " << error.message() << "\n";
            socket_.shutdown(tcp::socket::shutdown_both);
            socket_.close();
        }
    });
}