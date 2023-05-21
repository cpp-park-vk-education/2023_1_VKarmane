#include "VPNClient.hpp"

int main() {
     VPNClient cli;

     cli.setVpnTunContext("NL_tun", "Context.txt");

     cli.runTun(0);

     return 0;
}