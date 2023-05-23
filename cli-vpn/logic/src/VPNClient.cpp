#include "VPNClient.hpp"
#include "ConfigClient.hpp"
#include "vpnTunnel.hpp"

void VPNClient::setVpnTunContext(const std::string& name, std::string contextFilePath) {
     for (int i = 0; i < tunnels.size(); ++i) {
          if (tunnels[i].first == name) {
               std::cerr << "Error: Config file " << name << " already exist" << std::endl;
               return;
          }
     }

     ConfigClient config(name, contextFilePath);

     config.setUnspecified();
     
     config.buildConfig();

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
