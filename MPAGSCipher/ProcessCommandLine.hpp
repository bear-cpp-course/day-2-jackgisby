#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

// Standard library
#include <iostream>
#include <string>
#include <vector>

// Project files
#include "ProcessCommandLine.hpp"
#include "CipherMode.hpp"

/// @file

/// Structure containing program settings, set during command line processing
struct ProgramSettings {
    std::string input {""}; ///< text to be encrypted or decrypted
    std::string output {""}; ///< the encrypted or decrypted input text
    std::string key {"5"}; ///< the key for encryption or decryption
    bool debug {false}; ///< debug mode for verbose operation
    CipherMode mode {CipherMode::encrypt}; ///< whether to encrypt or decrypt the input text
};

/**
 * Processes command line arguments
 *
 * @param argc number of command line arguments
 * @param argv pointer to character vector of command line arguments
 * @param args program settings; will be changed based on user input
 *
 * @return true if input or output is empty
 */
bool processCommandLine(
        const int& argc,
        const char* argv[],
        ProgramSettings& args
);

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
