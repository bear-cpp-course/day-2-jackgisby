// Standard library
#include <iostream>
#include <string>

// Project files
#include "runCaesarCipher.hpp"
#include "CaesarCipher.hpp"

std::string runCaesarCipher(
        const std::string& inputText,
        const bool& encrypt,
        const CaesarCipher& cipher
) {
    /* Encrypt or decrypt a code based on the caesar cipher
     *
     * std::string inputText: Input code to be operated on
     * int key: the key to use to encode/decode the cipher
     * bool encrypt: whether to encrypt or decrypt the code
     *
     * return: encrypted/decrypted code
     */

    // reverse key for decryption
    int key {0};
    if (encrypt) {
        key = cipher.encryptKey_;
    } else {
        key = -cipher.encryptKey_;
    }

    // encrypt/decrypt each character and return final code
    std::string code {""};
    for (const char x : inputText) {
        // get alphabet position
        int base {0};
        for (int i {0}; i<26; ++i) {
            if (x == cipher.alphabet_.at(i)) {
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

        code += cipher.alphabet_.at(base);
    }

    return code;
}
