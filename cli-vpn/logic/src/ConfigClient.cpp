#include "ConfigClient.hpp"
//#include "../include/ConfigClient.hpp"

ConfigClient::ConfigClient():
     _address(nullptr), _privateKey(nullptr),
     _publicKeyServer(nullptr), _endpoint(nullptr),
     _keepAlive(25) {
          std::string path = getenv("HOME");
          path = path + "/.wireguard-cli";
          int status = mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
}


ConfigClient::ConfigClient(const std::string name, std::string configname): _name(name) {
     std::cout << "---------constr----------" << std::endl;

     std::ifstream configstream(configname);

     if (!configstream.is_open()) {
          std::cerr << "Error: Can't open file " << configname << " provided!" << std::endl;
          return;
     }

     if (isFileEmpty(configname)) {
          std::cerr << "Error: Provided file empty " << configname << " at least provide endpoint" << std::endl;
     }

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

     std::string cfgPath = configname;

     ParseFile parser;

     
     std::vector<std::vector<std::string>> parsed_vector = parser.getTokens(cfgPath);

     for (auto const& row : parsed_vector) {
          for (auto const& element : row) {
               std::cout << element << " ";
          }
          std::cout << std::endl;
     }

     *this = parsed_vector;

     this->print();

     // this->ipPublicKeyrequest();
}

ConfigClient& ConfigClient::operator=(const std::vector<std::vector<std::string>> parsed_vector) {
     std::cout << "coping" << std::endl;
     for (int i = 0; i < parsed_vector.size(); ++i) {
          if (parsed_vector[i].size() > 0) {
               if (parsed_vector[i][0] == "PrivateKey") {
                    this->setPrivateKey(parsed_vector[i][1]);
               }

               if (parsed_vector[i][0] == "Address") {
                    this->setAddress(parsed_vector[i][1]);
               }

               if (parsed_vector[i][0] == "DNS") {
                    this->setDns(parsed_vector[i]);
               }

               if (parsed_vector[i][0] == "PublicKey") {
                    this->setPublicKey(parsed_vector[i][1]);
               }

               if (parsed_vector[i][0] == "AllowedIPs") {
                    this->setAllowedIPs(parsed_vector[i]);
               }

               if (parsed_vector[i][0] == "Endpoint") {
                    std::cout << parsed_vector[i][1] << std::endl;
                    this->setEndpoint(parsed_vector[i][1]);
               }

               if (parsed_vector[i][0] == "PersistentKeepalive") {
                    this->setKeepAlive(std::stoul(parsed_vector[i][1]));
               }

               if (parsed_vector[i][0] == "URLlist") {
                    std::cout << "lol" << std::endl;
                    for (const auto& el : parsed_vector[i]) {
                         std::cout << el << ' ';
                    }
                    
                    this->_allowedIPs = parsed_vector[i];
                    _allowedIPs.erase(_allowedIPs.begin());
               
                    for (const auto& el : _allowedIPs) {
                         std::cout << el << ' ';
                    }
               }

               if (parsed_vector[i][0] == "Endpoint") {
                    this->setEndpoint(parsed_vector[i][1]);
               }
          }
     }
     return *this;
}

ConfigClient& ConfigClient::operator=(const ConfigClient& config) {
     _address = config._address;
     _privateKey = config._privateKey;
     _publicKeyServer = config._publicKeyServer;
     _endpoint = config._endpoint;
     _keepAlive = config._keepAlive;

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
     if (!_publicKeyServer.empty() || !_privateKey.empty()) {
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
          std::getline(privateKeyFile, this->_privateKey);
          std::getline(publicKeyFile, this->_publicKeyClient);
          std::cout << "key pair -> " << this->_privateKey << std::endl
                    << this->_publicKeyClient << std::endl;
          privateKeyFile.close();
     }
     
}

int ConfigClient::ipPublicKeyRequest(const std::string& endpoint) {
     try {
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
               this->_publicKeyServer = pb;
               this->_address = address;
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

     if (_dnsList.size() == 0) {
          std::vector<std::string> dnslist;
          dnslist.push_back("8.8.8.8");
          dnslist.push_back("8.8.4.4");
          this->setDns(dnslist);
     }

     if (this->_keepAlive == 0) {
          this->_keepAlive = 25;
     }

     _endpoint = _endpoint + ":51285";
}



void ConfigClient::buildConfig() {
     std::string path = defaultPath + _name + ".conf";
     std::ofstream wg_config(path);

     wg_config << "[Interface]\n"
               << "Address = " << this->_address << "\n"
               << "PrivateKey = " << this->_privateKey << "\n"
               << "DNS = ";
     
     for (size_t i = 0; i < _dnsList.size() - 1; ++i) {
          wg_config << _dnsList[i] << ", ";
     }

     wg_config << _dnsList[_dnsList.size() - 1] << "\n"
               << "[Peer]\n"
               << "PublicKey = " << this->_publicKeyServer << "\n"
               << "AllowedIPs = ";

     for (size_t i = 0; i < _allowedIPs.size() - 1; ++i) {
          wg_config << _allowedIPs[i] << ", ";
     }
     
     wg_config << _allowedIPs[_allowedIPs.size() - 1] << "\n"
               << "Endpoint = " << this->_endpoint << "\n"
               << "PersistentKeepalive = " << this->_keepAlive << '\n';
     
     wg_config.close();     
}

void ConfigClient::changeAllowedIPs() {
     std::string path = defaultPath + _name + ".conf";
     std::ofstream wg_config(path);
}
