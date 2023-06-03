#include "ConfigClient.hpp"


ConfigClient::ConfigClient() {
     std::string path = getenv("HOME");
     path = path + "/.wireguard-cli";
     int status = mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
}


ConfigClient::ConfigClient(const std::string name, const std::string& configname): _name(name) {
     peerData.persistentKeepalive = 25;
     std::cout << "---------constr----------" << std::endl;

     std::ifstream configstream(configname);

     std::string path;
     path = defaultPath + "/wireguard-cli";
     int status = mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
     if (status == -1) {
          //ToDo handele error
     }

     path = path + '/' + _name;
     status = mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
     if (status == -1) {
          std::cerr << "Error: Directory named " << _name << " already exist try another confg name";
     }

     ConfigParser parser;

     
     parser.parseFile(configname);

     this->interfaceData = parser.getInterfaceData();
     this->peerData = parser.getPeerData();

     this->print();

     // this->ipPublicKeyrequest();
}

ConfigClient& ConfigClient::operator=(const ConfigClient& config) {
     this->interfaceData = config.interfaceData;
     this->peerData = config.peerData;
     return *this;
}
     
std::string ConfigClient::genPrivateKey() {
     // TODO: Key gen
     return "a";
}

std::string ConfigClient::genPublicKey(const std::string& private_key) {
     // TODO: Key gen
     return "b";
}

void ConfigClient::genPair() {
     if (!_publicKeyClient.empty() || !interfaceData.privateKey.empty()) {
          return;
     }

     std::string pathPublicKey = defaultPath + "/wireguard-cli/" + _name + "/publickey";
     std::string pathPrivateKey = defaultPath + "/wireguard-cli/" + _name + "/privatekey";
     
     std::string command = "wg genkey | tee " + pathPrivateKey +
                         " | wg pubkey > " + pathPublicKey;
     std::system(command.c_str());
     std::ifstream publicKeyFile(pathPublicKey);
     std::ifstream privateKeyFile(pathPrivateKey);

     std::cout << privateKeyFile.is_open() << ' ' << publicKeyFile.is_open() << std::endl;

     if (privateKeyFile.is_open() && publicKeyFile.is_open()) {
          std::getline(privateKeyFile, this->interfaceData.privateKey);
          std::getline(publicKeyFile, this->_publicKeyClient);
          std::cout << "key pair -> " << this->interfaceData.privateKey << std::endl
                                      << this->_publicKeyClient << std::endl;
          privateKeyFile.close();
     }
     
}

int ConfigClient::ipPublicKeyRequest(const std::string& endpoint) {
     try {
          std::cout << "endpoint" << endpoint << " " << std::endl;

          Client cli(endpoint, "2003");

          cli.connect();

          cli.send(this->_publicKeyClient);

          std::string response = cli.receive();
          if (!cli.response_checker(response)) {
               // TODO: retry request throw exception
               return 505;
          }

          std::stringstream response_parse(response);
          std::string pb, address;

          while (response_parse >> pb >> address) {
               this->peerData.publicKey = pb;
               this->interfaceData.address = address;
          }

     } catch (std::exception& error) {
          std::cerr << "Error: " << error.what() << std::endl;
          return -1;
     }
     
     return 0;
}

void ConfigClient::setUnspecified() {
     std::cout << "setting unsecifyed" << std::endl;
     if (peerData.allowedIPs.size() == 0) {
          std::cout << "Null Why" << std::endl; 
          std::vector<std::string> allowedips;
          allowedips.push_back("0.0.0.0/0");
          this->setAllowedIPs(allowedips);

     } else {
          std::cout << "Have some sites!!!!!!!!!!!" << std::endl;
          if (!isIP4(peerData.allowedIPs[0])) {
               std::cout << "Here" << std::endl;
               for (const auto& el: peerData.allowedIPs) {
                    std::cout << el << std::endl;
               }

               std::vector<std::string> ipList;

               DnsRequest request;
               std::string ans;

               for (int i = 0; i < peerData.allowedIPs.size(); ++i) {
                    request.Request(peerData.allowedIPs[i]);
                    ans = request.getPoint();

                    std::stringstream ss(ans);
                    std::string token;

                    while(std::getline(ss, token, ',')) {
                        ipList.push_back(token);
                    }
               }
               
               for (const auto& el: ipList) {
                    std::cout << el << std::endl;
               }

               this->peerData.allowedIPs.clear();
               this->setAllowedIPs(ipList);
          }
     }

     if (interfaceData.dnsServers.size() == 0) {
          std::vector<std::string> dnslist;

          dnslist.push_back("8.8.8.8");
          dnslist.push_back("8.8.4.4");

          this->setDns(dnslist);
     }

     if (this->peerData.persistentKeepalive == 0) {
          this->peerData.persistentKeepalive = 25;
     }

     if (this->interfaceData.privateKey.empty()) {
          std::string pathPrivateKey = defaultPath + "/wireguard-cli/" + _name + "/privatekey";
          std::ifstream privateKeyFile(pathPrivateKey);

          if (privateKeyFile.is_open()) {
               std::string line;

               std::getline(privateKeyFile, line);

               this->setPrivateKey(line);
          }
     }

     peerData.endpoint = peerData.endpoint + ":51285";
}



void ConfigClient::buildConfig() {
     std::string path = defaultPath + _name + ".conf";
     std::ofstream wg_config(path);

     wg_config << "[Interface]\n"
               << "Address = " << this->interfaceData.address << "\n"
               << "PrivateKey = " << this->interfaceData.privateKey << "\n"
               << "DNS = ";
     
     for (size_t i = 0; i < interfaceData.dnsServers.size() - 1; ++i) {
          wg_config << interfaceData.dnsServers[i] << ", ";
     }

     wg_config << interfaceData.dnsServers[interfaceData.dnsServers.size() - 1] << "\n"
               << "[Peer]\n"
               << "PublicKey = " << this->peerData.publicKey << "\n"
               << "AllowedIPs = ";

     for (size_t i = 0; i < peerData.allowedIPs.size() - 1; ++i) {
          wg_config << peerData.allowedIPs[i] << ", ";
     }
     
     wg_config << peerData.allowedIPs[peerData.allowedIPs.size() - 1] << "\n"
               << "Endpoint = " << this->peerData.endpoint << "\n"
               << "PersistentKeepalive = " << 25 << '\n';
     
     wg_config.close();     
}

void ConfigClient::changeAllowedIPs() {
     const std::string path = defaultPath + _name + ".conf";
     std::fstream filestream(path, std::ios::in | std::ios::out);

     if (!filestream.is_open()) {
          std::cout << "Error opening file!" << std::endl;
     }

     std::vector<std::string> lines;
     std::string line;

     bool isAllowdSection = false;

     while (std::getline(filestream, line)) {
          if (line == "[Peer]") {
               isAllowdSection = true;
          }

          if (isAllowdSection && line.find("AllowedIPs = ") != std::string::npos) {
               line = "AllowedIPs = ";
               for (int i = 0; i < peerData.allowedIPs.size(); ++i) {
                    line += peerData.allowedIPs[i];
               }

               lines.push_back(line);
          }
     }

     for (const auto& line: lines) {
          filestream << line << std::endl;
     }
}     
