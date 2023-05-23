cmake_minimum_required(VERSION 3.26.3)

project(client)

include_directories(logic/src)
include_directories(logic/include)

include_directories(handshake/headers)
include_directories(handshake/src)

set (SOURCES
     main.cpp
     logic/src/ConfigClient.cpp
     logic/src/VPNClient.cpp
     logic/src/Parser.cpp
     handshake/src/ClientHandshake.cpp
)

set (HEADERS
     logic/include/ConfigClient.hpp
     logic/include/Parser.hpp
     logic/include/VPNClient.hpp
     logic/include/vpnTunnel.hpp
     handshake/headers/ClinetHandshake.hpp
)

add_executable(client ${SOURCES} ${HEADERS})