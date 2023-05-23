#pragma once

#include <iostream>

#include <string>

#include <regex> // Mask on name to

#include <GeoIP.h>

bool isValidName(const std::string& name) {
     std::regex pattern("\\d+\\.\\d+\\.\\d+\\.\\d+");

     return (std::regex_match(name, pattern)) ? false : true;
}

std::string ipToCountryCode (const std::string& name) {
     GeoIP *gi = GeoIP_open("/usr/share/GeoIP/GeoIP.dat", GEOIP_STANDARD);
     const char *ip = name.c_str();
     const char *country_code = GeoIP_country_code_by_addr(gi, ip);
     if (country_code) {
          std::string country_name = GeoIP_country_name_by_name(gi, country_code);
          GeoIP_delete(gi);
          return country_name;
     }
     GeoIP_delete(gi);
     return ""; // or some other default value
}