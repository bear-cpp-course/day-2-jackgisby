#include <iostream>
#include <string>

int main() {
    // Take each letter from user input and in each case:
    //
    // - Convert to upper case
    // - Change numbers to words
    // - Ignore any other (non-alpha) characters
    // - In each case, add result to a string variable
    //
    // print out the new string

    char in_char{'x'};
    std::string code{""};

    while(std::cin >> in_char) {
        in_char = toupper(in_char);
        std::string str_char {in_char};

        // convert numbers to capital words
        switch(in_char) {
            case '1':
                str_char = "ONE";
                break;

            case '2':
                str_char = "TWO";
                break;

            case '3':
                str_char = "THREE";
                break;

            case '4':
                str_char = "FOUR";
                break;

            case '5':
                str_char = "FIVE";
                break;

            case '6':
                str_char = "SIX";
                break;

            case '7':
                str_char = "SEVEN";
                break;

            case '8':
                str_char = "EIGHT";
                break;

            case '9':
                str_char = "NINE";
                break;

            case '0':
                str_char = "ZERO";
                break;

            // if an alphanumeric non-number
            default:
                if (isalpha(in_char)) {
                    str_char = in_char;
                } else {
                    continue;
                }
        }

        code += str_char;
    }

    std::cout << code << "\n";
    return 0;
}
