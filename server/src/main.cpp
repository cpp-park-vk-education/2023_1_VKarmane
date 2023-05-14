#include <fstream>
#include <string>
#include <iostream>

int main() {
    std::ifstream file("config.conf");
    std::string actualContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    std::cout << actualContent;
    return 0;
}