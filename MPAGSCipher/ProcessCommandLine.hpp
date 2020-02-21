#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

// Standard library
#include <iostream>
#include <string>
#include <vector>

// Project files
#include "ProcessCommandLine.hpp"

/// Structure containing program settings, set during command line processing
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
 * @param args struct containing program settings
 *
 * @return true if input or output is empty
 */
bool processCommandLine(
        const int& argc,
        const char* argv[],
        ProgramSettings& args
);

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
