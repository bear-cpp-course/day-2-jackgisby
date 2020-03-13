// Standard library
#include <string>

// Project files
#include "CaesarCipher.hpp"
#include "CipherMode.hpp"

CaesarCipher::CaesarCipher(int& key)
: encryptKey_(key) {
}

CaesarCipher::CaesarCipher(std::string& key)
: encryptKey_(std::stoi(key)) {
}

std::string CaesarCipher::applyCipher(
        const std::string& inputText,
        const CipherMode& mode
        ) const {
    // reverse key for decryption
    int key {0};
    switch (mode) {
        case CipherMode::encrypt : {
            key = encryptKey_;
            break;
        }
        case CipherMode::decrypt : {
            key = -encryptKey_;
            break;
        }
    }

    // encrypt/decrypt each character and return final code
    std::string code {""};
    for (const char x : inputText) {
        // get alphabet position
        int base {0};
        for (int i {0}; i<26; ++i) {
            if (x == alphabet_.at(i)) {
                base = i;
            }
        }

        // get new alphabet position
        base = base + key;
        if (base < 0) {
            base = 26 + base;

        } else if (base > 25) {
            base -= 26;
        }

        code += alphabet_.at(base);
    }

    return code;
}

int CaesarCipher::getKey() const {
    return encryptKey_;
}

void CaesarCipher::setKey(int& key) {
    encryptKey_ = key;
}

std::string CaesarCipher::getAlphabet() const {
    return alphabet_;
}

void CaesarCipher::setAlphabet(std::string& alphabet) {
    alphabet_ = alphabet;
}
