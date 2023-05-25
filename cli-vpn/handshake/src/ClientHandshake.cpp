#include "ClientHandshake.hpp"

Client::Client(const std::string& server, const std::string& port): 
                _io_context(), _socket(_io_context) {    
    boost::asio::ip::tcp::resolver resolver(_io_context);
    boost::asio::ip::tcp::resolver::query query(server, port);
    _endpoint_it = resolver.resolve(query);
}


void Client::connect() {
    std::cout << "trying connection" << std::endl;
    boost::asio::connect(_socket, _endpoint_it);
}


void Client::send(const std::string& msg) {
    std::cout << "trying sending " << std::endl;
    boost::asio::write(_socket, boost::asio::buffer(msg));
}

std::string Client::receive() {
    boost::asio::streambuf buffer;
    boost::asio::read_until(_socket, buffer, '\n');

    std::string msg((std::istreambuf_iterator<char>(&buffer)), std::istreambuf_iterator<char>());

    std::cout << "recived smth check it out " << msg << std::endl;

    return msg;
}

// Debug function to check error in recived message

/*std::string Client::receive() {
boost::asio::streambuf buffer;
boost::system::error_code error;

size_t bytes_transferred = boost::asio::read(_socket, buffer, error);

if (error == boost::asio::error::eof) {
// End of file or connection closed by peer
std::cout << "Connection closed by peer" << std::endl;
return "";
}
else if (error) {
// Some other error occurred
std::cerr << "Receive failed: " << error.message() << std::endl;
return "";
}

std::string msg((std::istreambuf_iterator<char>(&buffer)), std::istreambuf_iterator<char>());

std::cout << "Received message: " << msg << std::endl;

return msg;
}*/

bool Client::response_checker(std::string response) {
    if (response.size() > 0) {
         return true; // ToDo checker
    }

    return false;
}
