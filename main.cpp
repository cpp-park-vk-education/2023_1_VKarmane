#include <iostream>
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>

class Session : public boost::enable_shared_from_this<Session> {
 public:
  typedef boost::shared_ptr<Session> pointer;

  Session(boost::asio::io_service& io_service) : socket_(io_service) {}

  boost::asio::ip::tcp::socket& socket() { return socket_; }

  void start() {
    boost::asio::async_read_until(socket_, receive_buffer_, '\n',
        boost::bind(&Session::handle_read, shared_from_this(),
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
  }

 private:
  void handle_read(const boost::system::error_code& error, size_t bytes_transferred) {
    if (!error) {
      std::string message(boost::asio::buffer_cast<const char*>(receive_buffer_.data()), bytes_transferred);
      std::cout << "Received message: " << message << std::endl;

      // TODO: process message here and prepare response
      std::string response = "Response from server.";

      boost::asio::async_write(socket_, boost::asio::buffer(response),
        boost::bind(&Session::handle_write, shared_from_this(),
        boost::asio::placeholders::error));
    }
    else {
      std::cerr << "Error while reading data: " << error.message() << std::endl;
    }
  }

  void handle_write(const boost::system::error_code &error) {
    if (!error) {
      std::cout << "Response sent." << std::endl;
    }
    else {
      std::cerr << "Error while sending response: " << error.message() << std::endl;
    }
  }

  boost::asio::ip::tcp::socket socket_;
  boost::asio::streambuf receive_buffer_;
};

class Server {
public:
  Server(boost::asio::io_service& io_service, short port) 
      : io_service_(io_service), acceptor_(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)) {
    start_accept();
  }

private:
  void start_accept() {
    Session::pointer new_session(new Session(io_service_));

    acceptor_.async_accept(new_session->socket(),
        boost::bind(&Server::handle_accept, this, new_session,
        boost::asio::placeholders::error));
  }

  void handle_accept(Session::pointer new_session, const boost::system::error_code& error) {
    if (!error) {
      new_session->start();
    }
    else {
      std::cerr << "Error while accepting connection: " << error.message() << std::endl;
    }

    start_accept();
  }

  boost::asio::io_service& io_service_;
  boost::asio::ip::tcp::acceptor acceptor_;
};

int main(int argc, char** argv) {
  try {
    if (argc != 2) {
      std::cerr << "Usage: ./server <port>" << std::endl;
      return 1;
    }

    boost::asio::io_service io_service;

    Server server(io_service, std::atoi(argv[1]));

    std::cout << "Server listening on port " << std::atoi(argv[1]) << std::endl;

    io_service.run();
  }
  catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  return 0;
}