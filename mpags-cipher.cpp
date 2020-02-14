// Standard library
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// Project files
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "runCaeserCipher.hpp"

int main(
        int argc,
        char* argv[]
        ) {

    const std::vector<std::string> cmdLineArgs {argv, argv+argc};
    std::string input {""};
    std::string output {""};
    int key {5};
    bool debug {false};
    bool encrypt {true};
    if (processCommandLine(input, output, cmdLineArgs, argc, debug, key, encrypt)) {
        std::cerr << "[error] please specify input and output paths" << "\n";
    }

    std::ifstream in_file {input};
    std::ofstream out_file {output};
    char in_char{'x'};
    std::string code{""};

    // convert input to formatted string
    if (debug) {
        std::cout << "input: ";
    }
    while(in_file >> in_char) {
        if (debug) {
            std::cout << in_char;
        }

        code += transformChar(in_char);
    }

    code = runCaeserCipher(code, key, encrypt);
    if (debug) {
        std::cout << "\n" << "output: " << code << "\n";
    }

    out_file << code;
    return 0;
}
