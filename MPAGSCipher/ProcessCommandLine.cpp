#include <iostream>
#include <string>
#include <vector>

bool processCommandLine(
        std::string& input,
        std::string& output,
        const std::vector<std::string>& cmdLineArgs,
        const int& argc,
        bool& debug
) {
    /* processes command line arguments
     *
     * string input: input string
     * string output: output string
     * cmdLineArgs: string vector of command line arguments
     * int argc: number of command line arguments
     * bool debug: activate program debug mode?
     *
     * return: were correct arguments passed?
     */

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
        }
    }

    return input.empty() or output.empty();
}
