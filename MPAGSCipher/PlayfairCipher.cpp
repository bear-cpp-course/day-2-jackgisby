// Standard library
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

// Project files
#include "PlayfairCipher.hpp"
#include "CipherMode.hpp"

PlayfairCipher::PlayfairCipher(std::string& key)
        : encryptKey_(key) {
    PlayfairCipher::generateGridKey();
}

std::string PlayfairCipher::applyCipher(
        const std::string& inputText,
        const CipherMode& mode
        ) const {

    std::string code {""};

    // Change J → I
    std::replace(code.begin(), code.end(), 'J', 'I');

    // If repeated chars in a digraph add an X or Q if XX
    for (int i {0}; i < inputText.length(); i += 2) {
        code.push_back(inputText[i]);

        if (inputText[i] == inputText[i + 1]) {
            if (inputText[i] == 'X') {
                code.push_back('Q');
            } else {
                code.push_back('X');
            }

            i--;
        } else {
            if (i+1 < inputText.length()) {
                code.push_back(inputText[i + 1]);
            }
        }
    }

    // if the size of input is odd, add a trailing Z
    if ((code.length() % 2) != 0) {
        code.push_back('Z');
    }

    // Loop over the input in Digraphs
    switch (mode) {
        case CipherMode::encrypt : {
            return playfairEncrypt(code);
        }
        case CipherMode::decrypt : {
            return playfairDecrypt(code);
        }
    }
}

std::string PlayfairCipher::playfairDecrypt(std::string &code) const {
    return "whoops";
}

std::string PlayfairCipher::playfairEncrypt(std::string &code) const {
    std::pair<int, int> coordA;
    std::pair<int, int> coordB;
    std::string translation {""};

    for (int i {0}; i < code.length(); i += 2) {
        // - Find the coords in the grid for each digraph
        coordA = reverseGridKey_.at(code[i]);
        coordB = reverseGridKey_.at(code[i + 1]);

        // - Apply the rules to these coords to get 'new' coords
        auto gridShift = [] (int& coord) {
            if (++coord == 6) {
                coord = 1;
            }

            return coord;
        };
        if (coordA.first == coordB.first) {
            gridShift(coordA.first);
            gridShift(coordB.first);
        } else if (coordA.second == coordB.second) {
            gridShift(coordA.second);
            gridShift(coordB.second);
        } else {
            std::swap(coordA.second, coordB.second);
        }

        // - Find the letter associated with the new coords
        translation.push_back(forwardGridKey_.at(coordA));
        translation.push_back(forwardGridKey_.at(coordB));
    }

    return translation;
}

std::string PlayfairCipher::getKey() const {
    return encryptKey_;
}

void PlayfairCipher::setKey(std::string& key) {
    encryptKey_ = key;
    generateGridKey();
}

std::string PlayfairCipher::getAlphabet() const {
    return alphabet_;
}

void PlayfairCipher::setAlphabet(std::string& alphabet) {
    alphabet_ = alphabet;
}

void PlayfairCipher::generateGridKey() {
    // append alphabet
    std::string key {encryptKey_ + alphabet_};

    // Make sure the key is upper case
    std::transform(key.begin(), key.end(), key.begin(), ::toupper);

    // Remove non-alpha characters
    key.erase(std::remove_if(key.begin(), key.end(), [] (char& c) { return !isalpha(c); } ), key.end());

    // Change J -> I
    std::replace(key.begin(), key.end(), 'J', 'I');

    // Remove duplicated letters
    std::string duplicates {};
    auto duplicate_check = [&duplicates] (char& c) {
        if (duplicates.find(c) != std::string::npos) {
            return true;
        } else {
            duplicates.push_back(c);
            return false;
        }
    };

    key.erase(std::remove_if(key.begin(), key.end(), duplicate_check), key.end());

    // Store the coords of each letter
    int x {1};
    int y {1};
    for (int i {0}; i < 25; ++i) {
        // generate pairs of coords and key
        std::pair<int, int> coord {x, y};
        std::pair<std::pair<int, int>, char> coordToChar {coord, key[i]};
        std::pair<char, std::pair<int, int>> charToCoord {key[i], coord};

        // generate map
        forwardGridKey_.insert(coordToChar);
        reverseGridKey_.insert(charToCoord);

        // move coordinates
        y++;
        if (y == 6) {
            y = 1;
            x++;
        }
    }
}
