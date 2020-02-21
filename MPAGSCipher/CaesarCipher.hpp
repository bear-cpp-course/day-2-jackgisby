#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

// Standard library

// Project files
#include "CaesarCipher.hpp"

//! Caesar Cipher object and methods
class CaesarCipher {
private:
    int encryptKey_;
    std::string alphabet_ {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

public:
    // constructors
    explicit CaesarCipher(int& key);
    explicit CaesarCipher(std::string& key);

    // primary class method
    std::string applyCipher(
            const std::string &inputText,
            const bool &encrypt
            ) const;

    // get/set private variables
    int getKey() const;
    void setKey(const int& key);

    std::string getAlphabet() const;
    void setAlphabet(std::string& alphabet);
};

#endif //MPAGSCIPHER_CAESARCIPHER_HPP
