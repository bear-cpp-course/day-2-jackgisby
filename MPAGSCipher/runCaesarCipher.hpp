#ifndef MPAGSCIPHER_RUNCAESARCIPHER_HPP
#define MPAGSCIPHER_RUNCAESARCIPHER_HPP

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
);

#endif //MPAGSCIPHER_RUNCAESARCIPHER_HPP
