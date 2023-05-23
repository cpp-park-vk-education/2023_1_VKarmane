#include "VPNClient.hpp"

int main() {
     VPNClient cli;

     std::cout << "--------init---------" << std::endl;

     cli.printTunnels();

     return 0;
}

// VPNClient (_name, _frontdata) -> Checking if _name exist std::cerr
// -> 