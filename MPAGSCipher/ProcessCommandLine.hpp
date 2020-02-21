#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

// Standard library
#include <iostream>
#include <string>
#include <vector>

// Project files
#include "ProcessCommandLine.hpp"

/**
 * Structure containing program settings, set during command line processing
 *
 * @param input text to be encrypted or decrypted
 * @param output the encrypted or decrypted input text
 * @param key the key for encryption or decryption
 * @param debug debug mode for verbose operation
 * @param encrypt whether to encrypt or decrypt the input text
 */
struct ProgramSettings {
    std::string input {""};
    std::string output {""};
    std::string key {"5"};
    bool debug {false};
    bool encrypt {true};
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
