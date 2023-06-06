#pragma once

#include <string>
#include <iostream>

class vpnTun {
public:
     vpnTun(const std::string& name): _name(name) {}

     void up() { // script from folder pass?
          std::string command = "sudo wg-quick up " + _name;
          if (system(command.c_str()) == -1) {
               throw std::runtime_error("WireGuard startup error");
          }
     }

     void down() {
          std::string command = "sudo wg-quick down " + _name;
          system(command.c_str());
     }

     void reboot() {
          // log  reboot
          this->down();
          // log tun[i] down
          this->up();
          //log tun[i] up
          
     }
     
private:
     static size_t _id;
     std::string _name;
};


// tun_1
// tun_2 Click edit window -> cfg_edit -> save -> tunnels[i].config.changeCfg(file)
//                                                      если вызвали tunels[i].reboot();