#include "VPNClient.hpp"

int main() {
     VPNClient cli;

     ConfigClient cfg("NL_tun","testCfg.txt");

     cfg.buildConfig();

     cli.runTun(0);

     return 0;
}