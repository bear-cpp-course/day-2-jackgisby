// Standard library
#include <string>

// Project files
#include "TransformChar.hpp"

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
        // convert numbers to letters
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

        default:
            if (isalpha(in_char)) {  // capitalise remaining alphanumeric characters
                return std::string {static_cast<char>(toupper(in_char))};
            } else { // remove non-alphanumeric characters
                return "";
            }
    }
}
