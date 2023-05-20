#pragma once

#include <vector>
#include <string>
#include <algorithm>
#include "ConfigClient.hpp"

class ParseFile {
public:
     ParseFile() = default;

     ConfigClient parseConfig(std::string filePath) {
          if (!isValid(filePath)) {
               //ToDo Handle Error
          }

          ConfigClient cfg;
          std::ifstream filestream;
          std::string line;

          while (std::getline(filestream, line)) {
               if (line.find("PrivateKey") != std::string::npos) {
                    line.erase(remove(line.begin(), line.end(), ' '), line.end());
                    std::string key(line.substr(line.find("=") + 1));
                    cfg.setPrivateKey(key);
               }

               if (line.find("Address") != std::string::npos) {
                    line.erase(remove(line.begin(), line.end(), ' '), line.end());
                    std::string key(line.substr(line.find("=") + 1));
                    cfg.setAddress(key);
               }

               if (line.find("DNS") != std::string::npos) {
                    line.erase(remove(line.begin(), line.end(), ' '), line.end());
                    std::string key(line.substr(line.find("=") + 1));
                    
                    std::vector<std::string> dnslist;

                    std::stringstream ss(key);
                    std::string token;

                    while (std::getline(ss, token, ',')) {
                         dnslist.push_back(token);
                    }

                    cfg.setDns(dnslist);
               }

               if (line.find("PublicKey") != std::string::npos) {
                    line.erase(remove(line.begin(), line.end(), ' '), line.end());
                    std::string key(line.substr(line.find("=") + 1));
                    cfg.setPublicKey(key);
               }

               if (line.find("AllowedIPs") != std::string::npos) {
                    line.erase(remove(line.begin(), line.end(), ' '), line.end());
                    std::string key(line.substr(line.find("=") + 1));

                    std::vector<std::string> allowedips;

                    std::stringstream ss(key);
                    std::string token;

                    while (std::getline(ss, token, ',')) {
                         allowedips.push_back(token);
                    }

                    cfg.setAllowedIPs(allowedips);
               }

               if (line.find("Endpoint") != std::string::npos) {
                    line.erase(remove(line.begin(), line.end(), ' '), line.end());
                    std::string key(line.substr(line.find("=") + 1));
                    cfg.setEndpoint(key);
               }

               if (line.find("PersistentKeepalive") != std::string::npos) {
                    line.erase(remove(line.begin(), line.end(), ' '), line.end());
                    std::string key(line.substr(line.find("=") + 1));
                    cfg.setKeepAlive(std::stoul(key));
               }
          }

          return cfg;
     }

     std::vector<std::string> parseUrls(std::string filename) {
          std::vector<std::string> v;
          std::ifstream filestream(filename);
          std::string line;
          while (std::getline(filestream, line)) {
               if (line.find("URLlist") != std::string::npos) {
                    line.erase(remove(line.begin(), line.end(), ' '), line.end());
                    std::string key(line.substr(line.find("=") + 1));

                    std::vector<std::string> allowedips;

                    std::stringstream ss(key);
                    std::string token;

                    while (std::getline(ss, token, ',')) {
                         allowedips.push_back(token);
                    }

                    return allowedips;
               }
          }
          return v;
     }

     bool isValid(std::string path) {
          std::ifstream input_filestream(path);
          std::string line;

          if (input_filestream.is_open()) {
               while (std::getline(input_filestream, line)) {
                    if (line.find("[Interface]") == std::string::npos) {
                         //ToDo wrong cfg
                         return false;
                    }

                    if (line.find("PrivateKey") == std::string::npos) {
                         //ToDo No PrivateKey Found
                         return false;
                    }

                    if (line.find("Address") == std::string::npos) {
                         //ToDo No address
                         return false;
                    }

                    if (line.find("DNS") == std::string::npos) {
                         //Todo DNS
                         return false;
                    }

                    if (line.find("[Peer]") == std::string::npos) {
                         //ToDo No Peer
                         return false;
                    }

                    if (line.find("PublicKey") == std::string::npos) {
                         //ToDo no pubkey
                         return false;
                    }

                    if (line.find("AllowedIPs") == std::string::npos) {
                         //ToDo no AllowedIPs
                         return false;
                    }

                    if (line.find("Endpoint") == std::string::npos) {
                         // ToDo no Endpoint
                         return false;
                    }

                    if (line.find("PersistentKeepalive") == std::string::npos) {
                         //ToDo HandelPresistent
                    }
               }
          }
          return true;
     }
private:
     std::string getDNS();

     std::vector<std::string> getAllowedIPs();

     std::string getPrivateKey();

     std::string getPublicKey();

     std::string getEndpoint();

     std::string getKeepAlive();

     std::string getUrlsList();
};