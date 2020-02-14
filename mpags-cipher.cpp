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

    // initialise program arguments
    const std::vector<std::string> cmdLineArgs {argv, argv+argc};
    std::string input {""};
    std::string output {""};
    int key {5};
    bool debug {false};
    bool encrypt {true};

    // process arguments & check that input/output are supplied
    if (processCommandLine(input, output, cmdLineArgs, argc, debug, key, encrypt)) {
        std::cerr << "[error] please specify input and output paths" << "\n";
    }

    // setup program input/outputs
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

    in_file.close();

    // convert formatted string to ciphered string & output
    code = runCaeserCipher(code, key, encrypt);
    if (debug) {
        std::cout << "\n" << "output: " << code << "\n";
    }

    out_file << code;
    out_file.close();

    return 0;
}
