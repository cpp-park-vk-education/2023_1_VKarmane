#pragma once

#include <string>
#include <iostream>

class vpnTun {
public:
     vpnTun(const std::string& name): _name(name) {}

     void setUpContext();

     void up() {
          std::string command = "sudo wg-quick up " + _name;
          if (system(command.c_str()) == -1) {
               throw std::runtime_error("WireGuard startup error");
          }
     }

     void down() {
          std::string command = "sudo wg-quick down " + _name;
          system(command.c_str());
     }
     
private:
     static size_t _id;
     std::string _name;
};