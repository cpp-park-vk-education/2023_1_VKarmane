#include "ConfigClient.hpp"

int main() {
    std::string name = "test_tun";
    std::string file = "test1.conf";
    ConfigClient config(name, file);

    config.genPair();

    config.setUnspecified();

    config.buildConfig();

    config.print();
    return 0;
}
