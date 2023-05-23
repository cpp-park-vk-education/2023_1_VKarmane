#include <iostream>

#include "VPNClient.hpp"

int main() {
     std::string filename = "testCfg.txt";

     std::string name = "NL_tun";

     // name = getname()

     VPNClient client;

     client.setVpnTunContext(name, filename);
     
     client.runTun(name);

     char q;

     std::cin >> q;

     if (q == 'q')
          client.stopTun(name);
     client.stopTun(name);
     return 0;
}