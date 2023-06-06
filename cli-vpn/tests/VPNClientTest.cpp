#include <gtest/gtest.h>
#include "VPNClient.hpp"

TEST(VPNClientTest, setVpnTunContextTest) {
    VPNClient client;
    client.setVpnTunContext("test", "../tests/context.conf");

    // Check if the config was created correctly
    std::ifstream file("../tests/test.conf");
    bool exists = file.good();
    file.close();
    EXPECT_TRUE(exists);

    // Check if the tunnel object was created
    bool tunnelExists = false;
    for(int i = 0; i < client.tunnels.size(); ++i) {
        if (client.tunnels[i].first == "test") {
            tunnelExists = true;
            break;
        }
    }
    EXPECT_TRUE(tunnelExists);
}

TEST(VPNClientTest, runTunTest) {
    VPNClient client;
    // Start the tunnel
    client.setVpnTunContext("test", "../tests/context.conf");
    client.runTun("test");

    // Check if the tunnel is running
    bool running = false;
    for(int i = 0; i < client.tunnels.size(); ++i) {
        if (client.tunnels[i].first == "test") {
            running = client.tunnels[i].second.isUp();
            break;
        }
    }
    EXPECT_TRUE(running);
}

TEST(VPNClientTest, stopTunTest) {
    VPNClient client;
    // Start the tunnel
    client.setVpnTunContext("test", "../tests/context.conf");
    client.runTun("test");

    // Stop the tunnel
    client.stopTun("test");

    // Check if the tunnel is down
    bool stopped = true;
    for(int i = 0; i < client.tunnels.size(); ++i) {
        if (client.tunnels[i].first == "test") {
            stopped = !client.tunnels[i].second.isUp();
            break;
        }
    }
    EXPECT_TRUE(stopped);
}

TEST(VPNClientTest, rebootTunTest) {
    VPNClient client;
    // Start the tunnel
    client.setVpnTunContext("test", "../tests/context.conf");
    client.runTun("test");

    // Reboot the tunnel
    client.rebootTun("test");

    // Check if the tunnel is running again
    bool running = false;
    for(int i = 0; i < client.tunnels.size(); ++i) {
        if (client.tunnels[i].first == "test") {
            running = client.tunnels[i].second.isUp();
            break;
        }
    }
    EXPECT_TRUE(running);
}

TEST(VPNClientTest, printTunnelsTest) {
    testing::internal::CaptureStdout(); // Redirect std::cout
    VPNClient client;
    client.setVpnTunContext("test", "../tests/context.conf");
    client.printTunnels();
    std::string output = testing::internal::GetCapturedStdout(); // Get std::cout output
    EXPECT_EQ(output, "test, \n"); // Test if the output matches
}