#include "VPNClient.hpp"
#include "ConfigClient.hpp"
#include "vpnTunnel.hpp"

void VPNClient::setVpnTunContext(const std::string& name, std::string contextFilePath) {
     ConfigClient config(const std::string& name, contextFilePath);
     config.genPair();
     config.ipPublicKeyrequest();
     config.setUnspecified();
     config.buildConfig();
     contextstream.close();

     vpnTun tun(name);

     tunnels.push_back(tun);
}


void VPNClient::runTun(size_t id) {
     try {
          tunnels[i].up();
     } catch (std::exception& error) {
          std::cerr << "Error: " << error.what() << std::endl;
     }
}


void VPNClient::stopTun(size_t id) {
     try {
          tunnels[i].down();
     } catch (std::exception& error) {
          std::cerr << "Error: " << error.what() << std::endl;
     }
}


void VPNClient::rebootTun(size_t id) {
     return;
}
