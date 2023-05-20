#include "VPNClient.hpp"
#include "ConfigClient.hpp"
#include "vpnTunnel.hpp"

void VPNClient::setVpnTunContext(const std::string& name, std::string contextFilePath) {
     ConfigClient config(name, contextFilePath);
     config.setUnspecified();
     config.buildConfig();

     vpnTun tun(name);

     tunnels.push_back(tun);
}


void VPNClient::runTun(size_t id) {
     try {
          tunnels[id].up();
     } catch (std::exception& error) {
          std::cerr << "Error: " << error.what() << std::endl;
     }
}


void VPNClient::stopTun(size_t id) {
     try {
          tunnels[id].down();
     } catch (std::exception& error) {
          std::cerr << "Error: " << error.what() << std::endl;
     }
}


void VPNClient::rebootTun(size_t id) {
     return;
}
