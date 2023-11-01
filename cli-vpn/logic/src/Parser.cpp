#include "Parser.hpp"


#include <iostream>
#include <fstream>

#include <unordered_map>

#include <regex>

bool ConfigParser::checkConfigFile(const std::string& filename) {
	std::ifstream configFile(filename);
	if (!configFile.is_open()) {
		std::cout << "Failed to open config file: " << filename << std::endl;
		return false;
	}

	std::string line;
	std::vector<std::string> requiredFields = {"[Interface]", "Address", "PrivateKey", "DNS", "[Peer]", "PublicKey", "AllowedIPs", "Endpoint", "PersistentKeepalive"};
	std::vector<bool> foundFields(requiredFields.size(), false);

	while (std::getline(configFile, line)) {
		for (size_t i = 0; i < requiredFields.size(); ++i) {
		if (line.find(requiredFields[i]) != std::string::npos) {
			foundFields[i] = true;
			break;
		}
		}
	}

	configFile.close();

	for (bool found : foundFields) {
		if (!found) {
		return false;
		}
	}

	return true;
}

void ConfigParser::parseFile(const std::string& filename) {
	std::ifstream file(filename);
	if (!file) {
		std::cerr << "Failed to open file: " << filename << std::endl;
		return;
	}

	if (!checkConfigFile(filename)) {
		parseCustom(filename);
		return;
	}

	std::string line;
	std::string currentSection;

	while (std::getline(file, line)) {
		if (!line.empty() && line[0] == '#') {
		continue;
		} else if (!line.empty() && line[0] == '[' && line[line.length() - 1] == ']') {
		currentSection = line.substr(1, line.length() - 2);
		} else {
		parseLine(line, currentSection);
		}
	}

	file.close();
}

InterfaceData ConfigParser::getInterfaceData() const {
	return interfaceData;
}

PeerData ConfigParser::getPeerData() const {
	return peerData;
}

std::vector<std::string> ConfigParser::getAllowedIPs() const {
	return peerData.allowedIPs;
}


void ConfigParser::print() {
	std::cout << interfaceData.address << std::endl
			<< interfaceData.privateKey << std::endl;
	for (const auto& el : interfaceData.dnsServers) {
		std::cout << el << ", ";
	}

	std::cout << peerData.publicKey << std::endl;
	for (const auto& el: peerData.allowedIPs) {
		std::cout << el << ", ";
	}
	std::cout << peerData.endpoint << std::endl
			 << peerData.persistentKeepalive << std::endl;
}


void ConfigParser::parseLine(const std::string& line, const std::string& currentSection) {
	std::cout << line << std::endl;
	size_t delimiterPos = line.find('=');
	if (delimiterPos != std::string::npos) {
	std::string key = line.substr(0, delimiterPos);
	
	std::string value = line.substr(delimiterPos + 1);
	
	trim(key);
	trim(value);

	if (currentSection == "Interface") {
		parseInterfaceLine(key, value);
	} else if (currentSection == "Peer") {
		parsePeerLine(key, value);
	}
	}
}

void ConfigParser::parseInterfaceLine(const std::string& key, const std::string& value) {
	if (key == "Address") {
		interfaceData.address = value;
	} else if (key == "PrivateKey") {
		interfaceData.privateKey = value;
	} else if (key == "DNS") {
		std::istringstream iss(value);
		std::string dns;

		while (std::getline(iss, dns, ',')) {
		trim(dns);
		interfaceData.dnsServers.push_back(dns);
		}
	}
}

void ConfigParser::parsePeerLine(const std::string& key, const std::string& value) {
	if (key == "PublicKey") {
		peerData.publicKey = value;
	} else if (key == "AllowedIPs") {
		std::istringstream iss(value);
		std::string allowedIP;
		
		while (std::getline(iss, allowedIP, ',')) {
		trim(allowedIP);
		peerData.allowedIPs.push_back(allowedIP);
		}
	} else if (key == "Endpoint") {
		peerData.endpoint = value;
	} else if (key == "PersistentKeepalive") {
		peerData.persistentKeepalive = std::stoi(value);
	} else {
		std::cerr << "Unknown key in [Peer] section: " << key << std::endl;
	}
}

void ConfigParser::parseCustom(const string file) {
	std::ifstream filestream(file);
	string line;
	while (std::getline(filestream, line)) {
		line.erase(remove(line.begin(), line.end(), ' '), line.end());
		string key;

		if (line.find("URLlist") != string::npos) {
		key = line.substr(line.find("=") + 1);

		std::istringstream iss(key);
		std::string allowedIP;

		while (std::getline(iss, allowedIP, ',')) {
			trim(allowedIP);
			peerData.allowedIPs.push_back(allowedIP);
		}
		} else if (line.find("Endpoint") != string::npos) {
		key = line.substr(line.find("=") + 1);
		peerData.endpoint = key;
		}
	}
	filestream.close();
}

void ConfigParser::trim(std::string& str) {
    if (!str.empty())
        return;
	
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');

    str = str.substr(first, last - first + 1);
}