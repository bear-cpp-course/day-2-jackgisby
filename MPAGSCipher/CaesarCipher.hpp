#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

// Standard library
#include <string>

// Project files
#include "Cipher.hpp"
#include "CaesarCipher.hpp"
#include "CipherMode.hpp"

/// @file

/**
 * Implementation of the caesar cipher
 *
 * @param encryptKey_ the key used for encryption and decryption
 * @param alphabet_ the allowable characters for ciphers
 */
class CaesarCipher : public Cipher {
private:
    int encryptKey_;
    std::string alphabet_ {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

public:
    /**
     *  Create a caesar cipher class based on a key
     *
     * @param key encryption key
     */
    explicit CaesarCipher(int& key);

    /**
     * Create a caesar cipher class based on a key
     *
     * @param key encryption key
     */
    explicit CaesarCipher(std::string& key);

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
            ) const override;

    /**
     * Get the cipher's key value
     *
     * @return The value of the encryption key
     */
    int getKey() const;

    /**
     * Set the cipher's key value
     *
     * @param key The new key for encryption
     */
    void setKey(int& key);

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

#endif //MPAGSCIPHER_CAESARCIPHER_HPP
