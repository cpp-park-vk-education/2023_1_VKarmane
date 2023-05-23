#include "VPNClient.hpp"

int main() {
     VPNClient cli;

     std::cout << "--------init---------" << std::endl;

     ConfigClient cfg("NL_tun","testCfg.txt");
     
     cfg.ipPublicKeyrequest();

     cfg.setUnspecified();

     std::cout << "--------parsing---------" << std::endl;

     cfg.buildConfig();

     //cfg.set<smth> ... -> cfg.reloadCfg(); 

     std::cout << "--------chekout-cfg---------" << std::endl;
     cli.setVpnTunContext("NL_tun", "/etc/wireguard/"); // input front data here creating cfg
     cli.runTun(0);

     return 0;
}

// VPNClient (_name, _frontdata) -> Checking if _name exist std::cerr
// -> 