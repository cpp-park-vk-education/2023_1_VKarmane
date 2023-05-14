#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include <unordered_map>
#include "config.hpp"

using boost::asio::ip::tcp;

class Server {
 public:
    Server(boost::asio::io_service &io_service, Config &config, unsigned int port)
        : acceptor_(io_service, tcp::endpoint(tcp::v4(), port)),
          config_(config) {}

    void run() {
        accept();
    }

 private:
    void accept() {
        tcp::socket socket(acceptor_.get_executor());
        acceptor_.async_accept(socket, [this, &socket]
        (const boost::system::error_code &error) {
        if (!error) {
            handle_connection(std::move(socket));
        }
        accept(); });
    }

    void handle_connection(tcp::socket socket) {
        try {
            std::string client_ip_address = socket.remote_endpoint().address().to_string();
            boost::asio::streambuf buffer;
            boost::asio::async_read_until(socket, buffer, '\n', [this, &socket, &buffer, &client_ip_address](const boost::system::error_code &error, size_t bytes_transferred)
                                          {
            if (!error) {
                std::string public_key(boost::asio::buffers_begin(buffer.data()), boost::asio::buffers_end(buffer.data()) - 1);

                std::string ipClientOnServer = config_.addPeer(public_key);

                std::string message = "IP: " + ipClientOnServer + "\nPublic key: " + config_.getPublicKey() + "\n";
                boost::asio::async_write(socket, boost::asio::buffer(message), [this, &socket](const boost::system::error_code& error, size_t bytes_transferred) {
                    socket.shutdown(tcp::socket::shutdown_both);
                    socket.close();
                });
            } else {
                std::cerr << "Error in async_read_until: " << error.message() << "\n";
                socket.shutdown(tcp::socket::shutdown_both);
                socket.close();
            } });
        }
        catch (std::exception &e) {
            std::cerr << "Exception in handle_connection: " << e.what() << "\n";
        }
    }

    tcp::acceptor acceptor_;
    Config &config_;
};
