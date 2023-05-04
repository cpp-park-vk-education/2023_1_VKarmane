// Copyright 2023 Kosmatoff
#pragma once

#include <vector>
#include <unordered_map>
#include <string>

class ICongif {
 public:
    virtual void makeConfig() = 0;
    virtual void chageConfig() = 0;
};

class Config : public ICongif {
 public:
    void makeConfig() override;
    void chageConfig();
    void deleteConfig();
 private:
    int peer;
    int port;
    std::vector<std::string> ipull;
};
