#include <string>

class WireguardKey {
 public:
    WireguardKey();
    std::string getPulicKey();
    std::string getPrivateKey();
    bool isValidWireguardKey(const std::string& key);

 private:
    void createKey();

    std::string publicKey;
    std::string privateKey;
};
