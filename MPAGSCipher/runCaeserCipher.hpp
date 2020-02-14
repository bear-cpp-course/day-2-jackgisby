#ifndef MPAGSCIPHER_RUNCAESERCIPHER_HPP
#define MPAGSCIPHER_RUNCAESERCIPHER_HPP

// Standard library
#include <iostream>
#include <string>

// Project files
#include "runCaeserCipher.hpp"

std::string runCaeserCipher(
        const std::string& inputText,
        int key,
        const bool& encrypt
        );

#endif //MPAGSCIPHER_RUNCAESERCIPHER_HPP
