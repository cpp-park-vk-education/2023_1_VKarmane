#pragma once


#include <sstream>
#include <vector>
#include <string>


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
   bool checkConfigFile(const std::string& filename);

   void parseFile(const std::string& filename);

   InterfaceData getInterfaceData() const;
   PeerData getPeerData() const;

   std::vector<std::string> getAllowedIPs() const;

   void print();

 private:
   void parseLine(const std::string& line, const std::string& currentSection);

   void parseInterfaceLine(const std::string& key, const std::string& value);

   void parsePeerLine(const std::string& key, const std::string& value);

   void parseCustom(const string file);

   void trim(std::string& str);

   InterfaceData interfaceData;
   PeerData peerData;
};
