#include "VPNClient.hpp"
#include "ConfigClient.hpp"
#include "vpnTunnel.hpp"


VPNClient::VPNClient() {
    
    std::string directoryPath = defaultPath;

    try {
        for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
            std::string file = entry.path().filename().string(); 
            
            if (file.length() > 5 && file.substr(file.length() - 5) == ".conf") {
                std::string name(file.substr(0, file.find('.')));

                vpnTun tun(name);

                tunnels.push_back(std::make_pair(name, tun));
            }
        }
    } catch (const std::exception& error) {
        std::cout << "Error: " << error.what() << std::endl;
    }
}


void VPNClient::setVpnTunContext(const std::string& name, std::string contextFilePath) {
    for (int i = 0; i < tunnels.size(); ++i) {
        if (tunnels[i].first == name) {
            std::string path = defaultPath + '/' + name + ".conf";
            std::cout << "Config " << name << " exist" << std::endl;
               
            ConfigClient config(name, path);

            std::cout << "parsed>>>>" << std::endl;

            config.print();

            config.changeAllowedIPs(contextFilePath);

            config.print();

            return;
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
