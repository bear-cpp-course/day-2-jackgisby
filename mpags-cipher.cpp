#include <iostream>
#include <string>
#include <vector>

std::string transformChar(const char& in_char);

bool processCommandLine(
        std::string& input,
        std::string& output,
        const std::vector<std::string>& cmdLineArgs,
        const int& argc,
        bool& debug
);

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
