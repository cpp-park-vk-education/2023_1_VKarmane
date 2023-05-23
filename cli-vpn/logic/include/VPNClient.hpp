#pragma once

#include <utility>

#include "ConfigClient.hpp"
#include "vpnTunnel.hpp"

class VPNClient {
private:
     // VPNUser useer;
     std::vector<std::pair <std::string, vpnTun> > tunnels;

public:
     VPNClient() {
          // load old cfg
     }

     ~VPNClient() = default;


     void setVpnTunContext(const std::string& name, std::string contextFile);
     void runTun(const std::string& name); // input name instead id
     void stopTun(const std::string& name);
     void rebootTun(const std::string& name);
};


// Нажал на страну -> Записали в Файл Endpoint = ....
// Нажал подключиться 
// VPNClient client;
// client.SetUpVPNCOntext("file.txt")
// /etc/wireguard/_name/
