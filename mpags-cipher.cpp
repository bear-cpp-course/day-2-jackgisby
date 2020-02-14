#include <iostream>
#include <string>
#include <vector>


std::string transformChar (
        const char& in_char
        ) {
    /* transform character to formatted string
     *
     * const char: character to be converted
     *
     * return: formatted character
     */

    switch(in_char) {
        case '1':
            return "ONE";

        case '2':
            return "TWO";

        case '3':
            return "THREE";

        case '4':
            return "FOUR";

        case '5':
            return "FIVE";

        case '6':
            return "SIX";

        case '7':
            return "SEVEN";

        case '8':
            return "EIGHT";

        case '9':
            return "NINE";

        case '0':
            return "ZERO";

        // if an alphanumeric non-number
        default:
            if (isalpha(in_char)) {
                return std::string {static_cast<char>(toupper(in_char))};
            } else {
                return "";
            }
    }
}

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

int main(
        int argc,
        char* argv[]
        ) {

    const std::vector<std::string> cmdLineArgs {argv, argv+argc};
    std::string input {""};
    std::string output {""};
    bool debug {false};

    if (processCommandLine(input, output, cmdLineArgs, argc, debug)) {
        std::cerr << "[error] please specify input and output paths" << "\n";
    }

    char in_char{'x'};
    std::string code{""};

    // convert input to formatted string
    while(std::cin >> in_char) {
        if (in_char == 'q') { // alternative exit; remove for final program
            break;
        }

        code += transformChar(in_char);
    }

    if (debug) {
        std::cout << code << "\n";
    }
    return 0;
}
