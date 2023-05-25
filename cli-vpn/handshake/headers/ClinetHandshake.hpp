#pragma once

#include <iostream>
#include <boost/asio.hpp>

class Client {
public:
     Client(const std::string& server, const std::string& port);

     
     void connect();


     void send(const std::string& msg);

     std::string receive();

     // Debug function to check error in recived message
     
     /*std::string receive();*/

     bool response_checker(std::string response);
     
private:
     boost::asio::io_context _io_context;
     boost::asio::ip::tcp::socket _socket;
     boost::asio::ip::tcp::resolver::iterator _endpoint_it;
};