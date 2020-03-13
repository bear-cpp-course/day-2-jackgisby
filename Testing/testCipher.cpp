//! Unit tests for cipher classes
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Cipher.hpp"
#include "CipherMode.hpp"
#include "CaesarCipher.hpp"
#include "VigenereCipher.hpp"
#include "PlayfairCipher.hpp"
#include "TransformChar.hpp"

bool testCipher(const Cipher& cipher, const CipherMode mode,
        const std::string& inputText, const std::string& outputText
        ) {
    char in_char{'x'};
    std::string code{""};

    for (int i {0}; i < inputText.length(); ++i) {
        code += transformChar(inputText[i]);
    }
    std::cout << cipher.applyCipher(code, mode) << "\n";
    return cipher.applyCipher(code, mode) == outputText;
}

TEST_CASE("Ciphers generate correct output", "[cipher]") {
    std::string key {"5"};
    CaesarCipher caesar {key};
    PlayfairCipher playfair {key};
    VigenereCipher vigenere {key};

    REQUIRE(testCipher(caesar, CipherMode::encrypt, "hEll0Wor#ld", "MJQQEJWTBTWQI"));
    //REQUIRE(testCipher(playfair, CipherMode::encrypt, "hEll0Wor#ld", "JBMUOUATLXLSNZ"));
    REQUIRE(testCipher(vigenere, CipherMode::encrypt, "hEll0Wor#ld", "GDKKYDQNVNQKC"));

    REQUIRE(testCipher(caesar, CipherMode::decrypt, "hEll0Wor#ld", "CZGGUZMJRJMGY"));
    REQUIRE(testCipher(vigenere, CipherMode::decrypt, "hEll0Wor#ld", "IFMMAFSPXPSME"));
}
