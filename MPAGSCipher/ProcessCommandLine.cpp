// Standard library
#include <iostream>
#include <string>
#include <vector>

// Project files
#include "ProcessCommandLine.hpp"
#include "CipherMode.hpp"
#include "CipherType.hpp"

bool processCommandLine(
        const int& argc,
        const char* argv[],
        ProgramSettings& args
) {
    const std::vector<std::string> cmdLineArgs {argv, argv + argc};

    // process various arguments
    for (int i=0; i<argc; ++i) {
        if (cmdLineArgs.at(i) == "-h" or cmdLineArgs.at(i) == "--help") {
            std::cout << "Please read the source code for help" << "\n";

        } else if (cmdLineArgs.at(i) == "-o") {
            ++i;
            args.output = cmdLineArgs.at(i);

        } else if (cmdLineArgs.at(i) == "-i") {
            ++i;
            args.input = cmdLineArgs.at(i);

        } else if (cmdLineArgs[i] == "--version") {
            std::cout << "0.1.0" << "\n";

        } else if (cmdLineArgs[i] == "--debug" or cmdLineArgs[i] == "-d") {
            args.debug = true;

        } else if (cmdLineArgs[i] == "--key" or cmdLineArgs[i] == "-k") {
            ++i;
            args.key = cmdLineArgs.at(i);

        } else if (cmdLineArgs[i] == "--decrypt") {
            args.mode = CipherMode::decrypt;
        } else if (cmdLineArgs[i] == "--cipher") {
            ++i;
            if (cmdLineArgs.at(i) == "caesar") {
                args.type = CipherType::CaesarCipher;
            } else if (cmdLineArgs.at(i) == "playfair") {
                args.type = CipherType::PlayfairCipher;
            } else if (cmdLineArgs.at(i) == "vigenere") {
                args.type = CipherType::VigenereCipher;
            } else {
                std::cout << "Invalide cipher type provided, defaulting to Caesar cipher" << "\n";
            }
        }
    }

    // check that the user supplied both input and output
    return args.input.empty() or args.output.empty();
}


