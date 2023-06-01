cmake_minimum_required(VERSION 3.26.3)

project(client)

include_directories(src)
include_directories(include)

include_directories(../handshake/headers)
include_directories(../handshake/src)

set (SOURCES
     main.cpp
     src/ConfigClient.cpp
     ../handshake/src/DnsRequest.cpp
     ../handshake/src/ClientHandshake.cpp
     #src/VPNClient.cpp
     #src/Parser.cpp
)

set (HEADERS
     include/ConfigClient.hpp
     include/Parser.hpp
     ../handshake/headers/ClinetHandshake.hpp
     ../handshake/headers/DnsRequest.hpp
     #include/VPNClient.hpp
     #include/vpnTunnel.hpp
)

add_executable(client ${SOURCES} ${HEADERS})