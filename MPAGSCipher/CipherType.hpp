#ifndef MPAGSCIPHER_CIPHERTYPE_HPP
#define MPAGSCIPHER_CIPHERTYPE_HPP

// Project files
#include "CipherType.hpp"

/// @file

/**
 * Which type of encryption/decryption to use
 *
 * @param CaesarCipher use the caesar cipher
 * @param PlayfairCipher use the playfair cipher
 * @param VigenereCipher use the vigenere cipher
 */
enum class CipherType {
    CaesarCipher,
    PlayfairCipher,
    VigenereCipher
};

#endif //MPAGSCIPHER_CIPHERTYPE_HPP
