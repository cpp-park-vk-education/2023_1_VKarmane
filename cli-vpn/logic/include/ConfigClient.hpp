#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <sys/stat.h>
#include "Parser.hpp"
#include "../../handshake/headers/ClinetHandshake.hpp"

class ConfigClient {
public:
     ConfigClient();
     
     ConfigClient(const std::string name, std::string configname);

     ConfigClient(const ConfigClient& config):
          _address(config._address), _privateKey(config._privateKey),
          _publicKey(config._publicKey), _allowedIPs(config._allowedIPs),
          _endpoint(config._endpoint), _keepAlive(config._keepAlive) {}
     
     ConfigClient& operator=(const ConfigClient& config);

     void setAddress(std::string address) { _address = address; }
     void setPrivateKey(std::string privateKey) { _privateKey = privateKey; }
     void setDns(std::vector<std::string> dns) { _dnsList = dns; }
     void setPublicKey(std::string pubKey) { _publicKey = pubKey;}
     void setAllowedIPs(std::vector<std::string> ipList) { _allowedIPs = ipList; }
     void setEndpoint(std::string endpoint) { _endpoint = endpoint; }
     void setKeepAlive(size_t keepalive) { _keepAlive = keepalive; }

private:    
     void genPrivateKey();
     void genPublicKey(const std::string& private_key);
     void genPair();

public:
     void getPublicKey();
     void getPrivateKey();

     void setUnspecified();

     int ipPublicKeyrequest();
     void buildConfig();
     void changeConfig();
private:
     std::string _name;
     // Interface
     std::string _address;
     std::string _privateKey;
     std::vector<std::string> _dnsList;

     // Peer
     std::string _publicKey;
     std::vector<std::string> _allowedIPs;
     std::string _endpoint;
     size_t _keepAlive;

     std::string tunDataPath = "~/.wireguard-cli/";
     std::string frontendDataPath = "../../../metadata/";
     std::string defaultPath = "/etc/wireguard/";
};



bool response_checker(std::string response) {
     return true; // ToDo checker
}