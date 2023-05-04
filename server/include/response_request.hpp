// Copyright 2023 Kosmatoff
#pragma once

#include <string>
#include <memory>
#include "TCPConnect.hpp"

class RequestHandler {
 public:
    void handle_request(std::string, std::shared_ptr<TCPConnect>,
                        std::shared_ptr<ResponseHandler>);
};

class ResponseHandler {
 public:
    void send_response(std::shared_ptr<TCPConnect>,
                       std::string);
};
