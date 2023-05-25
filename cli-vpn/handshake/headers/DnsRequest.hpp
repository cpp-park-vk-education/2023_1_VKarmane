#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <string>

using boost::asio::ip::tcp;

class DnsRequest {
 public:
   void Request(const std::string& url);

   std::string getPoint();

 private:
 
   bool isIP4(const std::string& ipAddress);

   std::vector<std::string> endPoints;
};
