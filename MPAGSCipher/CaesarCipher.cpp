// Standard library
#include <string>

// Project files
#include "CaesarCipher.hpp"

CaesarCipher::CaesarCipher(int& key)
: encryptKey_(key) {
}

CaesarCipher::CaesarCipher(std::string& key)
: encryptKey_(std::stoi(key)) {
}
