#include "Parser.hpp"

std::vector<std::vector<std::string>> ParseFile::getTokens(const std::string filePath) {
     if (isValid(filePath)) {
          return parseConfig(filePath);
     } else {
          return parseNotStructured(filePath);
     }
}

bool ParseFile::isValid(std::string path) {
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


std::vector<std::vector<std::string>> ParseFile::parseConfig(std::string filePath) {
     if (!isValid(filePath)) {
          //ToDo handle error
     }
     size_t i = 0;
     std::vector<std::vector<std::string>> output(20);
     std::ifstream filestream(filePath);
     std::string line;
     std::string key;
     while (std::getline(filestream, line)) {
          if (line.find("PrivateKey") != std::string::npos) {
               line.erase(remove(line.begin(), line.end(), ' '), line.end());
               key = line.substr(line.find("=") + 1);
               
               output[i].push_back("PrivateKey");
               output[i].push_back(key);
          }
          if (line.find("Address") != std::string::npos) {
               line.erase(remove(line.begin(), line.end(), ' '), line.end());
               key = line.substr(line.find("=") + 1);
               
               output[i].push_back("Address");
               output[i].push_back(key);
          }
          if (line.find("DNS") != std::string::npos) {
               line.erase(remove(line.begin(), line.end(), ' '), line.end());
               key = line.substr(line.find("=") + 1);
               
               std::vector<std::string> dnslist;
               std::stringstream ss(key);
               std::string token;
               while (std::getline(ss, token, ',')) {
                    dnslist.push_back(token);
               }
               output[i].push_back("DNS");
               for (int j = 0; j < dnslist.size(); ++j) {
                    output[i].push_back(dnslist[j]);
               }
          }
          if (line.find("PublicKey") != std::string::npos) {
               line.erase(remove(line.begin(), line.end(), ' '), line.end());
               key = line.substr(line.find("=") + 1);
               
               output[i].push_back("PublicKey");
               output[i].push_back(key);
          }
          if (line.find("AllowedIPs") != std::string::npos) {
               line.erase(remove(line.begin(), line.end(), ' '), line.end());
               key = line.substr(line.find("=") + 1);
               std::vector<std::string> allowedips;
               std::stringstream ss(key);
               std::string token;
               while (std::getline(ss, token, ',')) {
                    allowedips.push_back(token);
               }
               output[i].push_back("AllowedIPs");
               for (int j = 0; j < allowedips.size(); ++j) {
                    output[i].push_back(allowedips[j]);
               }
          }
          if (line.find("Endpoint") != std::string::npos) {
               line.erase(remove(line.begin(), line.end(), ' '), line.end());
               key = line.substr(line.find("=") + 1);
               output[i].push_back("Endpoint");
               
               output[i].push_back(key);
          }
          if (line.find("PersistentKeepalive") != std::string::npos) {
               line.erase(remove(line.begin(), line.end(), ' '), line.end());
               key = line.substr(line.find("=") + 1);
               
               output[i].push_back("PersistentKeepalive");
               output[i].push_back(key);
          }
          ++i;
     }
     filestream.close();
     /*for (auto const& row : output) {
          for (auto const& element : row) {
               std::cout << element << " ";
          }
          std::cout << std::endl;
     }*/
     return output;
}


std::vector<std::vector<std::string>> ParseFile::parseNotStructured(std::string filename) {
     std::vector<std::vector<std::string>> output(2);
     std::ifstream filestream(filename);
     std::string line;
     size_t i = 0;
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
               output[i].push_back("URLlist");
               for (int j = 0; j < allowedips.size(); ++j) {
                    output[i].push_back(allowedips[j]);
               }
          }
          if (line.find("Endpoint") != std::string::npos) {
               line.erase(remove(line.begin(), line.end(), ' '), line.end());
               std::string key(line.substr(line.find("=") + 1));
               output[i].push_back("Endpoint");
               output[i].push_back(key);
          }
          ++i;
     }
     /*for (auto const& row : output) {
          for (auto const& element : row) {
               std::cout << element << " ";
          }
          std::cout << std::endl;
     }*/
     return output;
}
