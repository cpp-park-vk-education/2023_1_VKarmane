#include "ConfigClient.hpp"

#include <iostream>

int main() {
     std::cout << "---------init----------" << std::endl;
     ConfigClient cfg("NL_tun","testCfg.txt");
     std::cout << "---------print----------" << std::endl;
     cfg.print();
     cfg.buildConfig();
     std::cout << "-----------------------" << std::endl;
     cfg.print();
     std::cout << "---------end----------" << std::endl;

     return 0;
}