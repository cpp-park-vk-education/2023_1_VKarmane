// Copyright 2023 Kosmatoff

#include <iostream>

#include "server.hpp"

static Config* config_ptr = nullptr;

static void signalHandler(int signum) {
    std::cout << " Server terminated with abort all processes were closed successfully signal " << signum << std::endl;
    if (config_ptr) {
        config_ptr->stop();
    }
    exit(signum);
}

static void handleSignal(int signum) {
    signalHandler(signum);
}

int main() {
    try {
        std::string namePath = "/etc/wireguard/wg0.conf";
        Config config(namePath);
        config.run();
        boost::asio::io_context io_context;
        std::string ipServer = "127.0.0.1";
        Server server(io_context, 2003, config, ipServer);

        config_ptr = &config;
        std::signal(SIGINT, handleSignal);
        io_context.run();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
