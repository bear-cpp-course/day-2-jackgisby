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
     * int key: the key to use to encode/decode the cipher
     * bool encrypt: whether to encrypt or decrypt the code
     *
     * return: encrypted/decrypted code
     */

    const std::string alphabet {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    // reverse key for decryption
    if (encrypt == false) {
        key = -key;
    }

    // encrypt/decrypt each character and return final code
    std::string code {""};
    for (const char x : inputText) {
        // get alphabet position
        int base {0};
        for (int i {0}; i<26; ++i) {
            if (x == alphabet.at(i)) {
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

        code += alphabet.at(base);
    }

    return code;
}
