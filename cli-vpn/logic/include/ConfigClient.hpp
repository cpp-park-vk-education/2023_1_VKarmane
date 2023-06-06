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
#include "ClinetHandshake.hpp"
#include "DnsRequest.hpp"

using std::string;
using std::vector;

class ConfigClient {
 public:
     ConfigClient();
     
     ConfigClient(const string name, const string& configname);

     ConfigClient(const string name, vector<vector<string>> parse_input);

     ConfigClient(const ConfigClient& config):
          _name(config._name), _publicKeyClient(config._publicKeyClient),
          interfaceData(config.interfaceData.address, config.interfaceData.privateKey,
                        config.interfaceData.dnsServers),
          peerData(config.peerData.publicKey, config.peerData.allowedIPs,
                   config.peerData.endpoint, config.peerData.persistentKeepalive) {}
     
     ConfigClient& operator=(const ConfigClient& config);

     ConfigClient& operator=(const vector<vector<string>> parsed_vector);

     void setAddress(const string& address) { interfaceData.address = address; }
     void setPrivateKey(const string& privateKey) { interfaceData.privateKey = privateKey; }
     void setDns(vector<string> dns) { interfaceData.dnsServers = dns; }
     void setPublicKey(const string& pubKey) { peerData.publicKey = pubKey;}
     void setAllowedIPs(vector<string> ipList) { peerData.allowedIPs = ipList; }
     void setEndpoint(const string& endpoint) { peerData.endpoint = endpoint; }
     void setKeepAlive(size_t keepalive) { peerData.persistentKeepalive = keepalive; }

     friend bool isIP4(const string& ipAddress);
 private:
     string genPrivateKey();
     string genPublicKey(const string& private_key);

 public:
     void genPair();

     string getAddress() { return interfaceData.address; }
     string getPrivateKey() { return interfaceData.privateKey; }
     vector<string> getDns() { return interfaceData.dnsServers; }
     string getPublicKey() { return peerData.publicKey; }
     vector<string> getAllowedIPs() { return peerData.allowedIPs; }
     string getEndpoint() { return peerData.endpoint; }
     size_t getKeepAlive() { return peerData.persistentKeepalive; }

     void setUnspecified(); // Seting in config parametrs by default that i can

     int ipPublicKeyRequest(const string& endpoint);

     void buildConfig();                // Initiation config in /etc/wireguard folder
                                        // saving in /etc/wireguard/wireguard-cli/${_name}/
     
     void changeAllowedIPs();

     void print() {
          std::cout << "| _name = " << this->_name << std::endl
                    << "| _address = " << this->interfaceData.address << std::endl
                    << "| _privateKey = " << this->interfaceData.privateKey << std::endl
                    << "| _publicKeyServer = " << this->peerData.publicKey << std::endl
                    << "| _endpoint = " << this->peerData.endpoint << std::endl
                    << "| _keepAlive = " << this->peerData.persistentKeepalive << std::endl
                    << "| _publicKeyClient = " << this->_publicKeyClient << std::endl;
          std::cout << "| _dnsList = ";
          for (int i = 0; i < this->interfaceData.dnsServers.size(); ++i) {
               std::cout << this->interfaceData.dnsServers[i] << ", ";
          }
          std::cout << std::endl;

          std::cout << "| _allowedIPs = ";
          for (int i = 0; i < this->peerData.allowedIPs.size(); ++i) {
               std::cout << this->peerData.allowedIPs[i] << ", ";
          }
          std::cout << std::endl;
     }

     bool isFileEmpty(const string& filename) {
          string path = defaultPath + _name + ".conf";
          std::ifstream file(filename);
          return file.peek() == std::ifstream::traits_type::eof();
     }

     bool isConfigEmpty() {
          std::string path = defaultPath + _name + ".conf";
          std::ifstream file(path);
          return file.peek() == std::ifstream::traits_type::eof();
     }

 private:
     // Config & tun name
     string _name;
     // Interface
     InterfaceData interfaceData;

     // Peer
     PeerData peerData;

     //Handshake data
     string _publicKeyClient;

     string tunDataPath = getenv("HOME");
     string defaultPath = "/etc/wireguard/";
     string defaultPort = ":51285";
};
