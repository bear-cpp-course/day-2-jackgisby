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

VigenereCipher::VigenereCipher(std::string& key) {
    setKey(key);
}

std::string VigenereCipher::applyCipher(
        const std::string& inputText,
        const CipherMode& mode
        ) const {

    std::string code {""};
    std::string inputLetter {""};
    char keyLetter {};
    int j {0};

    // For each letter in input:
    for (int i {0}; i < inputText.length(); ++i) {
        // Find the corresponding letter in the key, repeating/truncating as required
        if (j < encryptKey_.length()) {
            keyLetter = encryptKey_[j];
            ++j;
        } else {
            j = 0;
            keyLetter = encryptKey_[j];
            ++j;
        }

        // Find the Caesar cipher from the lookup
        CaesarCipher currentCipher {charLookup_.at(keyLetter)};

        // Run the (de)encryption, add the result to the output
        inputLetter = inputText[i];
        code.push_back(currentCipher.applyCipher(inputLetter, mode)[0]);
    }

    return code;
}

std::string VigenereCipher::getKey() const {
    return encryptKey_;
}

void VigenereCipher::setKey(std::string& key) {
    // Make sure the key is uppercase
    std::transform(key.begin(), key.end(), key.begin(), ::toupper);

    // Remove non-alphabet characters
    key.erase(std::remove_if(key.begin(), key.end(), [] (char& c) { return !isalpha(c); } ), key.end());

    // Check if the key is empty and replace with default if so
    if (key.empty()) {
        encryptKey_ = "key";
    } else {
        encryptKey_ = key;
    }

    // loop over the key
    for (int i {0}; i < key.length(); ++i) {
        // Find the letter position in the alphabet
        int keyPos {static_cast<int>(alphabet_.find(key[i]))};

        // Create a CaesarCipher using this position as a key
        CaesarCipher cipherPos {keyPos};

        // Insert a std::pair of the letter and CaesarCipher into the lookup
        charLookup_.insert(std::pair<char, CaesarCipher> {key[i], cipherPos});
    }
}

std::string VigenereCipher::getAlphabet() const {
    return alphabet_;
}

void VigenereCipher::setAlphabet(std::string& alphabet) {
    alphabet_ = alphabet;
}