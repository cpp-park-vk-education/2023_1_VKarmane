#include "VPNClient.hpp"

int main() {
     VPNClient cli;

     std::cout << "--------init---------" << std::endl;

     ConfigClient cfg("NL_tun","testCfg.txt");

     std::cout << "--------parsing---------" << std::endl;

     cfg.buildConfig();

     std::cout << "--------chekout-cfg---------" << std::endl;
     cli.setVpnTunContext("NL_tun", "/etc/wireguard/");
     cli.runTun(0);

     return 0;
}