// Standard library
#include <iostream>
#include <string>

// Project files
#include "runCaeserCipher.hpp"

std::string runCaeserCipher(
        const std::string& inputText,
        int key,
        const bool& encrypt
        ) {
    /* Encrypt or decrypt a code based on the caeser cipher
     *
     * std::string inputText: Input code to be operated on
     * size_t key: the key to use to encode/decode the cipher
     * bool encrypt: whether to encrypt or decrypt the code
     *
     * return: encrypted/decrypted code
     */

    const std::string alphabet {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    if (encrypt == false) {
        key = -key;
    }

    std::string code {""};
    for (const char x : inputText) {
        int base {0};
        for (int i {0}; i<26; ++i) {
            if (x == alphabet.at(i)) {
                base = i;
            }
        }

        base = base + key;
        if (base < 0) {
            base = 26 + base;

        } else if (base > 25) {
            base -= 26;
        }

        code += alphabet.at(base);
    }

    return code;
}
