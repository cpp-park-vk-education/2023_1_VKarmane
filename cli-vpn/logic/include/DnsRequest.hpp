#pragma once

#include <iostream>
#include <ares.h>
#include <string>

class DnsRequest {
public:
     std::string operator()(std::string hostname) { 
          std::string ipAddress;
          // Initialize c-ares library
          ares_library_init(ARES_LIB_INIT_ALL);

          // Set up query request
          ares_channel channel;
          ares_options options;
          int optmask = 0;
          options.tries = 2;
          optmask |= ARES_OPT_TRIES;
          ares_init_options(&channel, &options, optmask);

          // Perform DNS lookup
          struct ares_addrinfo_hints hints;
          memset(&hints, 0, sizeof(hints));
          hints.ai_family = AF_INET;
          struct ares_addrinfo* result;
          int status = ares_getaddrinfo(channel, hostname.c_str(), NULL, &hints, &result);

          // Get IP address
          if (status == ARES_SUCCESS) {
               struct ares_addrinfo* rp = result;
               ipAddress = inet_ntoa(((struct sockaddr_in*)rp->ai_addr)->sin_addr);
          } else {
               std::cerr << "Error performing DNS query: " << ares_strerror(status) << std::endl;
          }

          // Clean up resources
          ares_freeaddrinfo(result);
          ares_destroy(channel);
          ares_library_cleanup();

          return ipAddress;
     }
};