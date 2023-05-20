#pragma once

#include "ConfigClient.hpp"
#include "vpnTunnel.hpp"

class VPNClient {
private:
     // VPNUser user_data;
     std::vector<vpnTun> tunnels;

public:
     VPNClient() = default;


     void setVpnTunContext(const std::string& name, std::string contextFile);
     void runTun(size_t id);
     void stopTun(size_t id);
     void rebootTun(size_t id);
};
