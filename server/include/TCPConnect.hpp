// Copyright 2023 Kosmatoff
#pragma once

#include <string>
#include <memory>

class IConnect : public std::enable_shared_from_this<IConnect> {
 public:
    virtual void connect() = 0;
    virtual void close() = 0;
 private:
    virtual void send_request(const std::string& request) = 0;
    virtual void receive_responce() = 0;
};

class TCPConnect : public IConnect {
 public:
    void connect() override {}
    void close() override {}
 private:
    void send_request(const std::string& request) override;
};

