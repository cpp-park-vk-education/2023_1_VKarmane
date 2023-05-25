#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>


class ParseFile {
 public:
     ParseFile() = default;

     std::vector<std::vector<std::string>> getTokens(const std::string filePath);

     bool isValid(std::string path);
     
 private:
     std::vector<std::vector<std::string>> parseConfig(std::string filePath);

     std::vector<std::vector<std::string>> parseNotStructured(std::string filename);
};