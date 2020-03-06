// Standard library
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// Project files
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "CaesarCipher.hpp"

int main(
        const int argc,
        const char* argv[]
        ) {

    // initialise program arguments
    ProgramSettings settings {};

    // process arguments & check that input/output are supplied
    if (processCommandLine(argc, argv, settings)) {
        std::cerr << "[error] please specify input and output paths" << "\n";
    }

    // setup program input/outputs
    std::ifstream in_file {settings.input};
    std::ofstream out_file {settings.output};
    char in_char{'x'};
    std::string code{""};

    // convert input to formatted string
    if (settings.debug) {
        std::cout << "input: ";
    }

    while(in_file >> in_char) {
        if (settings.debug) {
            std::cout << in_char;
        }

        code += transformChar(in_char);
    }

    in_file.close();

    // convert formatted string to ciphered string & output
    CaesarCipher cipher {settings.key};
    code = cipher.applyCipher(code, settings.mode);

    if (settings.debug) {
        std::cout << "\n" << "output: " << code << "\n";
    }

    out_file << code;
    out_file.close();

    return 0;
}
