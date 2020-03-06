#ifndef MPAGSCIPHER_PLAYFAIRCIPHER_HPP
#define MPAGSCIPHER_PLAYFAIRCIPHER_HPP

// Standard library
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

// Project files
#include "PlayfairCipher.hpp"
#include "CipherMode.hpp"

/// @file

/**
 * Implementation of the playfair cipher
 *
 * @param encryptKey_ the key used for encryption and decryption
 * @param alphabet_ the allowable characters for ciphers
 */
class PlayfairCipher {
private:
    std::string encryptKey_ {""};
    std::string alphabet_ {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    using PairToCharMap = std::map<std::pair<int, int>, char>;
    PairToCharMap encryptGridKey_;

    using CharToPairMap = std::map<char, std::pair<int, int>>;
    CharToPairMap decryptGridKey_;

    /**
     * Create a caesar cipher class based on a key
     *
     * @param key encryption key
     */
    void generategridKey();

public:
    /**
     * Create a caesar cipher class based on a key
     *
     * @param key encryption key
     */
    explicit PlayfairCipher(std::string& key);

    /**
     * Encrypt or decrypt a code based on the caesar cipher
     *
     * @param inputText text to be encrypted or decrypted
     * @param mode whether to encrypt or decrypt the input text
     *
     * @note uses the class's key & alphabet for encryption and decryption
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

#endif //MPAGSCIPHER_PLAYFAIRCIPHER_HPP
