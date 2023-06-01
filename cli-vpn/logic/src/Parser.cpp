
/*
using namespace std;

std::vector<std::vector<std::string>> ParseFile::getTokens(const std::string filePath) {
     std::cout << "entered" << std::endl;
     if (checkConfigFile(filePath)) {
          std::cout << "vaild cool" <<std::endl;
          return parseConfig(filePath);
     } else {
          std::cout << "mistakes who did this" <<std::endl;
          return parseNotStructured(filePath);
     }
      return parseNotStructured(filePath);
}

bool ParseFile::checkConfigFile(const std::string& filename) {
    std::ifstream configFile(filename);
    if (!configFile.is_open())
    {
        std::cout << "Failed to open config file: " << filename << std::endl;
        return false;
    }

    std::string line;
    std::vector<bool> foundFields(requiredFields.size(), false);

    while (std::getline(configFile, line))
    {
        for (size_t i = 0; i < requiredFields.size(); ++i)
        {
            if (line.find(requiredFields[i]) != std::string::npos)
            {
                foundFields[i] = true;
                break;
            }
        }
    }

    configFile.close();

    for (bool found : foundFields)
    {
        if (!found)
        {
            return false;
        }
    }

    return true;
}




void ParseFile::print() {
     for (auto const& row : parsed_file) {
          for (auto const& element : row) {
               std::cout << element << " ";
          }
          std::cout << std::endl;
     }
}


std::vector<std::vector<std::string>> ParseFile::parseConfig(std::string filePath) {
     if (validateFile(filePath)) {
          //ToDo handle error
     }
     size_t i = 0;
     std::vector<std::vector<std::string>> output(20);
     std::ifstream filestream(filePath);
     std::string line;
     std::string key;
     while (std::getline(filestream, line)) {
          if (line.find("PrivateKey") != std::string::npos) {
               line.erase(remove(line.begin(), line.end(), ' '), line.end());
               key = line.substr(line.find("=") + 1);
               
               output[i].push_back("PrivateKey");
               output[i].push_back(key);
          }
          if (line.find("Address") != std::string::npos) {
               line.erase(remove(line.begin(), line.end(), ' '), line.end());
               key = line.substr(line.find("=") + 1);
               
               output[i].push_back("Address");
               output[i].push_back(key);
          }
          if (line.find("DNS") != std::string::npos) {
               line.erase(remove(line.begin(), line.end(), ' '), line.end());
               key = line.substr(line.find("=") + 1);
               
               std::vector<std::string> dnslist;
               std::stringstream ss(key);
               std::string token;
               while (std::getline(ss, token, ',')) {
                    dnslist.push_back(token);
               }
               output[i].push_back("DNS");
               for (int j = 0; j < dnslist.size(); ++j) {
                    output[i].push_back(dnslist[j]);
               }
          }
          if (line.find("PublicKey") != std::string::npos) {
               line.erase(remove(line.begin(), line.end(), ' '), line.end());
               key = line.substr(line.find("=") + 1);
               
               output[i].push_back("PublicKey");
               output[i].push_back(key);
          }
          if (line.find("AllowedIPs") != std::string::npos) {
               line.erase(remove(line.begin(), line.end(), ' '), line.end());
               key = line.substr(line.find("=") + 1);
               std::vector<std::string> allowedips;
               std::stringstream ss(key);
               std::string token;
               while (std::getline(ss, token, ',')) {
                    allowedips.push_back(token);
               }
               output[i].push_back("AllowedIPs");
               for (int j = 0; j < allowedips.size(); ++j) {
                    output[i].push_back(allowedips[j]);
               }
          }
          if (line.find("Endpoint") != std::string::npos) {
               line.erase(remove(line.begin(), line.end(), ' '), line.end());
               key = line.substr(line.find("=") + 1);
               output[i].push_back("Endpoint");
               
               output[i].push_back(key);
          }
          if (line.find("PersistentKeepalive") != std::string::npos) {
               line.erase(remove(line.begin(), line.end(), ' '), line.end());
               key = line.substr(line.find("=") + 1);
               
               output[i].push_back("PersistentKeepalive");
               output[i].push_back(key);
          }
          ++i;
     }
     filestream.close();
     
     parsed_file = output;

     return output;
}


std::vector<std::vector<std::string>> ParseFile::parseNotStructured(std::string filename) {
     std::vector<std::vector<std::string>> output(2);
     std::ifstream filestream(filename);
     std::string line;
     size_t i = 0;
     while (std::getline(filestream, line)) {
          if (line.find("URLlist") != std::string::npos) {
               line.erase(remove(line.begin(), line.end(), ' '), line.end());
               std::string key(line.substr(line.find("=") + 1));
               std::vector<std::string> allowedips;
               std::stringstream ss(key);
               std::string token;
               
               while (std::getline(ss, token, ',')) {
                    allowedips.push_back(token);
               }
               output[i].push_back("URLlist");
               for (int j = 0; j < allowedips.size(); ++j) {
                    output[i].push_back(allowedips[j]);
               }
          }
          if (line.find("Endpoint") != std::string::npos) {
               line.erase(remove(line.begin(), line.end(), ' '), line.end());
               std::string key(line.substr(line.find("=") + 1));
               output[i].push_back("Endpoint");
               output[i].push_back(key);
          }
          ++i;
     }
     for (auto const& row : output) {
          for (auto const& element : row) {
               std::cout << element << " ";
          }
          std::cout << std::endl;
     }
     return output;
}
*/