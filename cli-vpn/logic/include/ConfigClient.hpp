#pragma once

// streams
#include <iostream>
#include <fstream>
#include <sstream>
// structures
#include <vector>
#include <string>
// system
#include <sys/stat.h>
#include <filesystem>
// Custom
#include "Parser.hpp"
#include "../../handshake/headers/ClinetHandshake.hpp"

class ConfigClient {
 public:
     ConfigClient();
     
     ConfigClient(const std::string name, std::string configname);

     ConfigClient(const std::string name, std::vector<std::vector<std::string>> parse_input);

     ConfigClient(const ConfigClient& config):
          _address(config._address), _privateKey(config._privateKey),
          _publicKeyServer(config._publicKeyServer), _allowedIPs(config._allowedIPs),
          _endpoint(config._endpoint), _keepAlive(config._keepAlive) {}
     
     ConfigClient& operator=(const ConfigClient& config);

     ConfigClient& operator=(const std::vector<std::vector<std::string>> parsed_vector);

     void setAddress(std::string address) { _address = address; }
     void setPrivateKey(std::string privateKey) { _privateKey = privateKey; }
     void setDns(std::vector<std::string> dns) { _dnsList = dns; }
     void setPublicKey(std::string pubKey) { _publicKeyServer = pubKey;}
     void setAllowedIPs(std::vector<std::string> ipList) { _allowedIPs = ipList; }
     void setEndpoint(std::string endpoint) { _endpoint = endpoint; }
     void setKeepAlive(size_t keepalive) { _keepAlive = keepalive; }

 private:    
     std::string genPrivateKey();
     std::string genPublicKey(const std::string& private_key);

 public:
     void genPair();

     std::string getAddress() { return _address; }
     std::string getPrivateKey() { return _privateKey; }
     std::vector<std::string> getDns() { return _dnsList; }
     std::string getPublicKey() { return _publicKeyServer;}
     std::vector<std::string> getAllowedIPs() { return _allowedIPs; }
     std::string getEndpoint() { return _endpoint; }
     size_t getKeepAlive() { return _keepAlive; }

     void setUnspecified(); // Seting in config parametrs by default that i can

     int ipPublicKeyRequest(const std::string& endpoint);

     void buildConfig();                 // Initiation config in /etc/wireguard folder
                                   // saving in /etc/wireguard/wireguard-cli/${_name}/

     void changeAllowedIPs();

     void print() {
          std::cout << "| _name = " << this->_name << std::endl
                    << "| _address = " << this->_address << std::endl
                    << "| _privateKey = " << this->_privateKey << std::endl
                    << "| _publicKeyServer = " << this->_publicKeyServer << std::endl
                    << "| _endpoint = " << this->_endpoint << std::endl
                    << "| _keepAlive = " << this->_keepAlive << std::endl
                    << "| _publicKeyClient = " << this->_publicKeyClient << std::endl;
          std::cout << "| _dnsList = ";
          for (int i = 0; i < this->_dnsList.size(); ++i) {
               std::cout << this->_dnsList[i] << ", ";
          }
          std::cout << std::endl;

          std::cout << "| _allowedIPs = ";
          for (int i = 0; i < this->_allowedIPs.size(); ++i) {
               std::cout << this->_allowedIPs[i] << ", ";
          }
          std::cout << std::endl;
     }

     bool isFileEmpty(const std::string& filename) {
          std::ifstream file(filename);
          return file.peek() == std::ifstream::traits_type::eof();
     }

 private:
     // Config & tun name
     std::string _name;
     // Interface
     std::string _address;
     std::string _privateKey;
     std::vector<std::string> _dnsList;

     // Peer
     std::string _publicKeyServer;
     std::vector<std::string> _allowedIPs;
     std::string _endpoint;
     size_t _keepAlive = 25;

     //Handshake data
     std::string _publicKeyClient;

     std::string tunDataPath = getenv("HOME");
     std::string defaultPath = "/etc/wireguard/";
     std::string defaultPort = ":51285";
};