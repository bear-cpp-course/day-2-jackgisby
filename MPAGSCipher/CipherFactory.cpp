// Standard library
#include <memory>

// Project files
#include "CipherFactory.hpp"
#include "CipherType.hpp"
#include "CaesarCipher.hpp"
#include "VigenereCipher.hpp"
#include "PlayfairCipher.hpp"

std::unique_ptr<Cipher> cipherFactory(CipherType& type, std::string& key) {
    switch (type) {
        case CipherType::CaesarCipher : {
            return std::make_unique<CaesarCipher>(key);
        }
        case CipherType::PlayfairCipher : {
            return std::make_unique<PlayfairCipher>(key);
        }
        case CipherType::VigenereCipher : {
            return std::make_unique<VigenereCipher>(key);
        }
    }
}