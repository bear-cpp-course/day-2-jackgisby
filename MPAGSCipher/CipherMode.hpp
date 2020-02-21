#ifndef MPAGSCIPHER_CIPHERMODE_HPP
#define MPAGSCIPHER_CIPHERMODE_HPP

// Project files
#include "CipherMode.hpp"

/**
 * Whether to encrypt or decrypt the input text
 *
 * @param encrypt encrypt the input text
 * @param decrypt decrypt the input text
 */
enum class CipherMode {
    encrypt,
    decrypt
};

#endif //MPAGSCIPHER_CIPHERMODE_HPP
