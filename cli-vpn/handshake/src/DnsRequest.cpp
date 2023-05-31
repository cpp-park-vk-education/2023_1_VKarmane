#include "DnsRequest.hpp"

void DnsRequest::Request(const std::string& url) {
     boost::asio::io_context io_context;
     tcp::resolver resolver(io_context);

     tcp::resolver::query query(url, "http");


     resolver.async_resolve(query,
     [&](const boost::system::error_code& error, const tcp::resolver::results_type& endpoints) {
          if (!error) {
               for (const auto& endpoint : endpoints) {
                    if (isIP4(endpoint.endpoint().address().to_string())) {
                         endPoints.push_back(endpoint.endpoint().address().to_string());
                    }
               }
          } else {
               std::cerr << "dnsError" << std::endl;
               std::cerr << "Ошибка при разрешении DNS: " << error.message() << std::endl;
          }
     });

     io_context.run();
}     

std::string DnsRequest::getPoint() {
     std::string returnString;
     if (!endPoints.empty()) {
          for (const auto it : endPoints) {
               returnString += it + "/32, ";
          }
          endPoints.clear();
          return returnString.substr(0, returnString.length() - 2);
     } else {
          returnString = "Error Invalid Arguments";
          return returnString;
     }
}

/*bool DnsRequest::isIP4(const std::string& ipAddress) {
     boost::system::error_code ec;
     boost::asio::ip::address_v4::from_string(ipAddress, ec);
     return !ec;
}*/