#pragma once

#include <iostream>
#include <boost/asio.hpp>

class Client {
public:
     Client(const std::string& server, const std::string& port):
          _io_context(), _socket(_io_context) {
               boost::asio::ip::tcp::resolver resolver(_io_context);
               boost::asio::ip::tcp::resolver::query query(server, port);
               _endpoint_it = resolver.resolve(query);
     }

     
     void connect() {
          boost::asio::connect(_socket, _endpoint_it);
     }


     void send(const std::string& msg) {
          boost::asio::write(_socket, boost::asio::buffer(msg));
     }

     std::string receive() {
          boost::asio::streambuf buffer;
          boost::asio::read_until(_socket, buffer, '\n');
          std::string msg((std::istreambuf_iterator<char>(&buffer)), std::istreambuf_iterator<char>());

          return msg;
     }

     bool response_checker(std::string response) {
          if (response.size() > 0) {
               return true; // ToDo checker
          }
          return false;
     }
private:
     boost::asio::io_context _io_context;
     boost::asio::ip::tcp::socket _socket;
     boost::asio::ip::tcp::resolver::iterator _endpoint_it;
};