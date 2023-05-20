cmake_minimum_required(VERSION 3.26.3)

project(client)

include_directories(src)
include_directories(include)
include_directories(../handshake/headers)
include_directories(../handshake/src)

set (SOURCES
     src/ConfigClient.cpp
     src/VPNClient.cpp
)

set (HEADERS
     include/ConfigClient.hpp
     include/Parser.hpp
     include/VPNClient.hpp
     include/vpnTunnel.hpp
)

add_executable(client ${SOURCES} ${HEADERS})