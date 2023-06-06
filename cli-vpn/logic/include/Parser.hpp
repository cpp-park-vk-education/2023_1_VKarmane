#pragma once

/*#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <map>
#include <string>

#include <regex>

using std::string;
using std::vector;


class ParseFile {
 public:
    ParseFile() = default;

    vector<vector<string>> getTokens(const string filePath);

    bool checkConfigFile(const std::string& filename);

    vector<vector<string>> getParsedFile() { return parsed_file; }

    void print();
     
 private:
   vector<vector<string>> parseConfig(string filePath);

   vector<vector<string>> parseNotStructured(string filename);

   vector<vector<string>> parsed_file;

   vector<string> requiredFields = {
       "[Interface]", "Address", "PrivateKey", "DNS", "[Peer]", "PublicKey", "AllowedIPs", "Endpoint"
   };
};*/

#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <string>
#include <unordered_map>

#include <regex>

using std::string;
using std::vector;
using std::stringstream;

struct InterfaceData {
   std::string address;
   std::string privateKey;
   std::vector<std::string> dnsServers;

   InterfaceData() = default;

   InterfaceData(std::string _address, std::string _privateKey,
                 std::vector<std::string> _dnsServers):
                 address(_address), privateKey(_privateKey), dnsServers(_dnsServers) {}

   InterfaceData(const InterfaceData& interface): address(interface.address),
      privateKey(interface.privateKey), dnsServers(interface.dnsServers) {}
};

struct PeerData {
   std::string publicKey;
   std::vector<std::string> allowedIPs;
   std::string endpoint;
   int persistentKeepalive;

   PeerData() = default;

   PeerData(std::string _publicKey, std::vector<std::string> _allowedIPs,
            std::string _endpoint, int _persistentKeepalive):
            publicKey(_publicKey), allowedIPs(_allowedIPs),
            endpoint(_endpoint), persistentKeepalive(_persistentKeepalive) {}
   
   PeerData(const PeerData& peer): publicKey(peer.publicKey),
      allowedIPs(peer.allowedIPs), endpoint(peer.endpoint), 
      persistentKeepalive(peer.persistentKeepalive) {}
};


class ConfigParser {
 public:
   bool checkConfigFile(const std::string& filename) {
      std::ifstream configFile(filename);
      if (!configFile.is_open()) {
         std::cout << "Failed to open config file: " << filename << std::endl;
         return false;
      }

      std::string line;
      std::vector<std::string> requiredFields = {"[Interface]", "Address", "PrivateKey", "DNS", "[Peer]", "PublicKey", "AllowedIPs", "Endpoint", "PersistentKeepalive"};
      std::vector<bool> foundFields(requiredFields.size(), false);

      while (std::getline(configFile, line)) {
         for (size_t i = 0; i < requiredFields.size(); ++i) {
            if (line.find(requiredFields[i]) != std::string::npos) {
               foundFields[i] = true;
               break;
            }
         }
      }

      configFile.close();

      for (bool found : foundFields) {
         if (!found) {
            return false;
         }
      }

      return true;
   }

   void parseFile(const std::string& filename) {
      std::ifstream file(filename);
      if (!file) {
         std::cerr << "Failed to open file: " << filename << std::endl;
         return;
      }

      if (!checkConfigFile(filename)) {
         parseCustom(filename);
         return;
      }

      std::string line;
      std::string currentSection;

      while (std::getline(file, line)) {
         if (!line.empty() && line[0] == '#') {
            continue;
         } else if (!line.empty() && line[0] == '[' && line[line.length() - 1] == ']') {
            currentSection = line.substr(1, line.length() - 2);
         } else {
            parseLine(line, currentSection);
         }
      }

      file.close();
   }

   InterfaceData getInterfaceData() const {
       return interfaceData;
   }

   PeerData getPeerData() const {
      return peerData;
   }

 private:
   void parseLine(const std::string& line, const std::string& currentSection) {
      size_t delimiterPos = line.find('=');
      if (delimiterPos != std::string::npos) {
        std::string key = line.substr(0, delimiterPos);
        std::string value = line.substr(delimiterPos + 1);
        trim(key);
        trim(value);
        if (currentSection == "Interface") {
            parseInterfaceLine(key, value);
        } else if (currentSection == "Peer") {
            parsePeerLine(key, value);
        }
      }
   }

   void parseInterfaceLine(const std::string& key, const std::string& value) {
      if (key == "Address") {
         interfaceData.address = value;
      } else if (key == "PrivateKey") {
         interfaceData.privateKey = value;
      } else if (key == "DNS") {
         std::istringstream iss(value);
         std::string dns;
         while (std::getline(iss, dns, ',')) {
            trim(dns);
            interfaceData.dnsServers.push_back(dns);
         }
      }
   }

   void parsePeerLine(const std::string& key, const std::string& value) {
      if (key == "PublicKey") {
         peerData.publicKey = value;
      } else if (key == "AllowedIPs") {
         std::istringstream iss(value);
         std::string allowedIP;
         while (std::getline(iss, allowedIP, ',')) {
            trim(allowedIP);
            peerData.allowedIPs.push_back(allowedIP);
         }
      } else if (key == "Endpoint") {
         peerData.endpoint = value;
      } else if (key == "PersistentKeepalive") {
         peerData.persistentKeepalive = std::stoi(value);
      } else {
         std::cerr << "Unknown key in [Peer] section: " << key << std::endl;
      }
   }

   void parseCustom(const string file) {
      std::ifstream filestream(file);
      string line;
      while (std::getline(filestream, line)) {
         line.erase(remove(line.begin(), line.end(), ' '), line.end());
         string key;

         if (line.find("URLlist") != string::npos) {
            key = line.substr(line.find("=") + 1);

            std::istringstream iss(key);
            std::string allowedIP;

            while (std::getline(iss, allowedIP, ',')) {
               trim(allowedIP);
               peerData.allowedIPs.push_back(allowedIP);
            }
         } else if (line.find("Endpoint") != string::npos) {
            key = line.substr(line.find("=") + 1);
            peerData.endpoint = key;
         }
      }
      filestream.close();
   }

   void trim(std::string& str) {
      size_t first = str.find_first_not_of(' ');
      size_t last = str.find_last_not_of(' ');
      str = str.substr(first, last - first + 1);
   }

   InterfaceData interfaceData;
   PeerData peerData;
};
