// Standard library
#include <iostream>
#include <string>
#include <vector>

// Project files
#include "ProcessCommandLine.hpp"

bool processCommandLine(
        const int& argc,
        const char* argv[],
        ProgramSettings& args
) {
    /* processes command line arguments
     *
     * string input: input string
     * string output: output string
     * vector(string) cmdLineArgs: string vector of command line arguments
     * int argc: number of command line arguments
     * bool debug: activate program debug mode?
     * int key: the key to use when encrypting/decrypting the string
     * bool encrypt: encrypt or decrypt the input string
     *
     * return: were correct arguments passed?
     */

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
            args.key = std::stoi(cmdLineArgs.at(i));

        } else if (cmdLineArgs[i] == "--decrypt") {
            args.encrypt = false;
        }
    }

    // check that the user supplied both input and output
    return args.input.empty() or args.output.empty();
}


