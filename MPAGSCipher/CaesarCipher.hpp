#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

// Standard library

// Project files
#include "CaesarCipher.hpp"

//! Caesar Cipher object and methods
class CaesarCipher {
public:
    explicit CaesarCipher(int& key);
    explicit CaesarCipher(std::string& key);

    const int encryptKey_;
    const std::string alphabet_ {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
};

#endif //MPAGSCIPHER_CAESARCIPHER_HPP
