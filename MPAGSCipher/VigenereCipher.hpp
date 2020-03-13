#ifndef MPAGSCIPHER_VIGENERECIPHER_HPP
#define MPAGSCIPHER_VIGENERECIPHER_HPP

// Standard library
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

// Project files
#include "VigenereCipher.hpp"
#include "CaesarCipher.hpp"
#include "CipherMode.hpp"

/// @file

/**
 * Implementation of the vigenere cipher
 *
 * @param encryptKey_ the key used for encryption and decryption
 * @param alphabet_ the allowable characters for ciphers
 */
class VigenereCipher {
private:
    std::string encryptKey_ {""};
    std::string alphabet_ {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    std::map<char,CaesarCipher> charLookup_;

public:
    /**
     *  Create a vigenere cipher class based on a key
     *
     * @param key encryption key
     */
    explicit VigenereCipher(std::string& key);

    /**
     * Encrypt or decrypt a code based on the caesar cipher
     *
     * @param inputText text to be encrypted or decrypted
     * @param mode whether to encrypt or decrypt the input text
     *
     * @return the encrypted or decrypted code
     */
    std::string applyCipher(
            const std::string& inputText,
            const CipherMode& mode
    ) const;

    /**
     * Get the cipher's key value
     *
     * @return The value of the encryption key
     */
    std::string getKey() const;

    /**
     * Set the cipher's key value
     *
     * @param key The new key for encryption
     */
    void setKey(std::string& key);

    /**
     * Get the cipher's alphabet
     *
     * @return The characters allowed for encryption and decryption
     */
    std::string getAlphabet() const;

    /**
     * Set the cipher's alphabet
     *
     * @param alphabet The new set of allowable characters for encryption and decryption
     */
    void setAlphabet(std::string& alphabet);
};

#endif //MPAGSCIPHER_VIGENERECIPHER_HPP
