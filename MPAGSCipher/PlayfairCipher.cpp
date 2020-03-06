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
    PlayfairCipher::generategridKey();
}

std::string PlayfairCipher::applyCipher(
        const std::string& inputText,
        const CipherMode& mode
        ) const {

    std::string code {inputText};

    // Change J → I

    // If repeated chars in a digraph add an X or Q if XX

    // if the size of input is odd, add a trailing Z

    // Loop over the input in Digraphs

    // - Find the coords in the grid for each digraph
    // - Apply the rules to these coords to get 'new' coords
// - Find the letter associated with the new coords
    // return the text
    return code;
}

std::string PlayfairCipher::getKey() const {
    return encryptKey_;
}

void PlayfairCipher::setKey(std::string& key) {
    encryptKey_ = key;
    generategridKey();
}

std::string PlayfairCipher::getAlphabet() const {
    return alphabet_;
}

void PlayfairCipher::setAlphabet(std::string& alphabet) {
    alphabet_ = alphabet;
}

void PlayfairCipher::generategridKey() {
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
    std::cout << duplicates << "\n";

    // Store the coords of each letter
    int x {1};
    int y {1};
    for (int i {0}; i < 25; i++) {
        // generate pairs of coords and key
        std::pair<int, int> coord {x, y};
        std::pair<std::pair<int, int>, char> coordToChar {coord, key[i]};
        std::pair<char, std::pair<int, int>> charToCoord {key[i], coord};

        // generate map
        encryptGridKey_.insert(coordToChar);
        decryptGridKey_.insert(charToCoord);

        // move coordinates
        y++;
        if (y == 6) {
            y = 1;
            x++;
        }
    }
}
