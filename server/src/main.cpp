// Copyright 2023 Kosmatoff

#include <iostream>
#include <memory>
#include "server.hpp"

static boost::asio::io_context* io_context_ptr = nullptr;

static void signalHandler(int signum) {
    std::cout << " Server terminated with abort all processes were closed successfully signal " << signum << std::endl;

    io_context_ptr->stop();
}

int main() {
    try {
        std::string namePath = "/etc/wireguard/wg0.conf";
        Config config(namePath);
        config.run();

        boost::asio::io_context io_context;
        io_context_ptr = &io_context;
        std::string ipServer = "45.82.15.27";
        int port = 2003;
        Server server(io_context, port, config, ipServer);

        std::signal(SIGINT, signalHandler);
        io_context.run();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    return 0;
}
