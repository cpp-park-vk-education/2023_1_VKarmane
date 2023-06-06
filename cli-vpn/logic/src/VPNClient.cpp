#include "VPNClient.hpp"
#include "ConfigClient.hpp"
#include "vpnTunnel.hpp"


VPNClient::VPNClient() {
     DIR* directory;
     struct dirent* file;

     int count = 0;

     if ((directory = opendir(defaultPath.c_str())) != nullptr) {
          while ((file = readdir(directory)) != nullptr) {

               if (file->d_type == DT_REG && file->d_name[strlen(file->d_name) - 5] == '.' 
                    && file->d_name[strlen(file->d_name) - 4] == 'c' 
                    && file->d_name[strlen(file->d_name) - 3] == 'o' 
                    && file->d_name[strlen(file->d_name) - 2] == 'n' 
                    && file->d_name[strlen(file->d_name) - 1] == 'f') {
                         std::string name;
                         for (int j = 0; j < strlen(file->d_name) - 5; j++)
                              name += file->d_name[j];
                         vpnTun tun(name);
                         tunnels.push_back(std::make_pair(name, tun));
               }
          }
          closedir(directory);
     }
}

void VPNClient::setVpnTunContext(const std::string& name, std::string contextFilePath) {
     for (int i = 0; i < tunnels.size(); ++i) {
          if (tunnels[i].first == name) {
               std::string path = defaultPath + '/' + name + ".conf";
               std::cout << "Config " << name << " exist" << std::endl;
               
               ConfigClient config(name, path);

          }
     }

     ConfigClient config(name, contextFilePath);

     config.genPair();

     config.ipPublicKeyRequest(config.getEndpoint());

     config.setUnspecified();

     config.buildConfig();

     config.print();

     vpnTun tun(name);

     tunnels.push_back(std::make_pair(name, tun));
}

void VPNClient::runTun(const std::string& name) {
     size_t id = 0;

     for (size_t i = 0; i < tunnels.size(); ++i) {
          if (tunnels[i].first == name) {
               id = i;
               break;
          }
     }


     try {
          tunnels[id].second.up();
     } catch (std::exception& error) {
          std::cerr << "Error: " << error.what() << std::endl;
     }
}


void VPNClient::stopTun(const std::string& name) {
     size_t id = 0;

     for (size_t i = 0; i < tunnels.size(); ++i) {
          if (tunnels[i].first== name) {
               id = i;
               break;
          }
     }

     try {
          tunnels[id].second.down();
     } catch (std::exception& error) {
          std::cerr << "Error: " << error.what() << std::endl;
     }
}


void VPNClient::rebootTun(const std::string& name) {
     stopTun(name);
     
     runTun(name);
}

void VPNClient::printTunnels() {
     for (int i = 0; i < tunnels.size(); ++i) {
          std::cout << tunnels[i].first << ", ";
     }

     std::cout << std::endl;
}
