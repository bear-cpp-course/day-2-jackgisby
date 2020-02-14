// Standard library
#include <iostream>
#include <string>
#include <vector>

// Project files
#include "ProcessCommandLine.hpp"

bool processCommandLine(
        std::string& input,
        std::string& output,
        const std::vector<std::string>& cmdLineArgs,
        const int& argc,
        bool& debug,
        int& key,
        bool& encrypt
) {
    /* processes command line arguments
     *
     * string input: input string
     * string output: output string
     * vector(string) cmdLineArgs: string vector of command line arguments
     * int argc: number of command line arguments
     * bool debug: activate program debug mode?
     * int key: the key to use when encrypting/decrypting the strnig
     * bool encrypt: encrypt or decrypt the input string
     *
     * return: were correct arguments passed?
     */

    // process various arguments
    for (int i=0; i<argc; ++i) {
        if (cmdLineArgs.at(i) == "-h" or cmdLineArgs.at(i) == "--help") {
            std::cout << "Please read the source code for help" << "\n";

        } else if (cmdLineArgs.at(i) == "-o") {
            ++i;
            output = cmdLineArgs.at(i);

        } else if (cmdLineArgs.at(i) == "-i") {
            ++i;
            input = cmdLineArgs.at(i);

        } else if (cmdLineArgs[i] == "--version") {
            std::cout << "0.1.0" << "\n";

        } else if (cmdLineArgs[i] == "--debug" or cmdLineArgs[i] == "-d") {
            debug = true;

        } else if (cmdLineArgs[i] == "--key" or cmdLineArgs[i] == "-k") {
            ++i;
            key = std::stoi(cmdLineArgs.at(i));

        } else if (cmdLineArgs[i] == "--decrypt") {
            encrypt = false;
        }
    }

    // check that the user supplied both input and output
    return input.empty() or output.empty();
}
