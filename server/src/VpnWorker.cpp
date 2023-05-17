// Copyright 2023 Kosmatoff

#include <VpnWorker.hpp>


boost::asio::ip::tcp::socket& VpnWorker::socket() {
    return _socket;
}

void VpnWorker::start() {
    doRead();
}

void VpnWorker::doRead() {
    auto self(shared_from_this());
    _socket.async_read_some(boost::asio::buffer(_data, max_length),
                            [this, self](boost::system::error_code ec, std::size_t length) {
                                if (!ec) {
                                    ipAddPeer = _config.addPeer(_data);
                                    doWrite();
                                }
                            });
}

void ::VpnWorker::doWrite() {
    auto self(shared_from_this());
    std::string message = ipAddPeer + "\n";
    boost::asio::async_write(_socket, boost::asio::buffer(message),
        [this, self](boost::system::error_code ec, std::size_t length) {
            if (!ec) {
                _socket.close();
            }
        });
}
