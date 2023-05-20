#include "ConfigClient.hpp"

ConfigClient::ConfigClient(): 
          _address(nullptr), _privateKey(nullptr),
          _publicKey(nullptr), _endpoint(nullptr),
          _keepAlive(25) {
               int status = mkdir("~/.wireguard-cli", 0777);
               if (status == -1) {
                    //ToDo handele error
               }
          }


ConfigClient::ConfigClient(const std::string name, std::string configname): _name(name) {
     std::string path = frontendDataPath + configname;
     std::ifstream cfgstream(path);
     //parseInputFile(cfgstream); ////////////////////////////
     ParseFile p;

     if (p.isValid(path)) {
          *this = p.parseConfig(path);
     } else {
          this->setAllowedIPs(p.parseUrls(path));
     }

     cfgstream.close();

     int status = mkdir("~/.wireguard-cli", 0777);
     if (status == -1) {
          //ToDo handele error
     }

     std::string folderPath = "~/.wireguard-cli/" + _name;
     status = mkdir(folderPath.c_str(), 0777);
     if (status == -1) {
          //ToDo error handle
     }
}

ConfigClient& ConfigClient::operator=(const ConfigClient& config) {
     _address = config._address;
     _privateKey = config._privateKey;
     _publicKey = config._publicKey;
     _endpoint = config._endpoint;
     _keepAlive = config._keepAlive;

     return *this;
}
     
void ConfigClient::genPrivateKey() {
     // TODO: Key gen
     return;
}

void ConfigClient::genPublicKey(const std::string& private_key) {
     // TODO: Key gen
     return;
}

void ConfigClient::genPair() {
     if (_publicKey.empty() || _privateKey.empty()) {
          //ToDo mistake handle
     }
     std::string pathPublicKey = "~/.wireguard-cli/" + _name + "/publickey";
     std::string pathPrivateKey = "~/.wireguard-cli/" + _name + "/privatekey";
     
     std::string command = "wg genkey | tee " + pathPrivateKey +
                              " | wg pubkey > " + pathPublicKey;
     std::system(command.c_str());
     std::ifstream publicKeyFile(pathPublicKey);
     std::ifstream privateKeyFile(pathPrivateKey);

     if (publicKeyFile.is_open() && privateKeyFile.is_open()) {
          std::getline(publicKeyFile, this->_publicKey);
          std::getline(privateKeyFile, this->_privateKey);
          publicKeyFile.close();
          privateKeyFile.close();
     }
     
}

int ConfigClient::ipPublicKeyrequest() {
     try {
          Client cli("45.82.15.27", "2003");
          cli.connect();
          cli.send(this->_publicKey);
          std::string response = cli.receive();
          if (!response_checker(response)) {
               // TODO: retry request throw exception
               return 505;
          }

     } catch (std::exception& error) {
          std::cerr << "Error: " << error.what() << std::endl;
          return -1;
     }
     
     return 0;
}

void ConfigClient::setUnspecified() {
     if (_allowedIPs.size() == 0) {
          std::vector<std::string> allowedips;
          allowedips.push_back("0.0.0.0/0");
          this->setAllowedIPs(allowedips);
     }

     if (_allowedIPs.size() == 0) {
          std::vector<std::string> dnslist;
          dnslist.push_back("8.8.8.8");
          dnslist.push_back("8.8.4.4");
          this->setDns(dnslist);
     }
}

void ConfigClient::buildConfig() {
     std::string path = defaultPath + _name;
     std::fstream wg_config(path);

     wg_config << "[Interface]\n"
               << "Address = " << this->_address << "\n"
               << "PrivateKey = " << this->_privateKey << "\n"
               << "DNS = ";
     
     for (size_t i = 0; i < _dnsList.size() - 1; ++i) {
          wg_config << _dnsList[i] << ", ";
     }

     wg_config << _dnsList[_dnsList.size() - 1] << "\n"
               << "[Peer]\n"
               << "PublicKey = " << this->_publicKey << "\n"
               << "AllowedIPs = ";

     for (size_t i = 0; i < _allowedIPs.size() - 1; ++i) {
          wg_config << _allowedIPs[i] << ", ";
     }
     
     wg_config << _allowedIPs[_allowedIPs.size() - 1] << "\n"
               << "Endpoint = " << this->_endpoint << "\n"
               << "PersistentKeepalive = " << this->_keepAlive;
     
     wg_config.close();
}


void ConfigClient::changeConfig() {
     return;
}