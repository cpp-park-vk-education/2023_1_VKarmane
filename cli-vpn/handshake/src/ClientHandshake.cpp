/*#include <iostream>
#include <exception>
#include "ClinetHandshake.hpp"


int main() {
     try {
          Client cli("45.82.15.27", "2003");
          cli.connect();
          cli.send("lol");
          cli.receive();
     } catch (std::exception& error) {
          std::cerr << "Error: " << error.what() << std::endl;
     }
     return 0;
}*/
