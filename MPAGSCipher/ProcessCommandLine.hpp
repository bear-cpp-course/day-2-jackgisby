#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

// Standard library
#include <iostream>
#include <string>
#include <vector>

// Project files
#include "ProcessCommandLine.hpp"

//! Setup program arguments
struct ProgramSettings {
    std::string input {""};
    std::string output {""};
    std::string key {"5"};
    bool debug {false};
    bool encrypt {true};
};

//! Process command line arguments
bool processCommandLine(
        const int& argc,
        const char* argv[],
        ProgramSettings& args
);

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
