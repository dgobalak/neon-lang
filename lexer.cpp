#include "lexer.hpp"

#include <ctype>
#include <stdlib>

token_holder_t getToken() {
    static int lastChar = ' ';
    token_holder_t tokenHolder;

    // Skip whitespace
    while (isspace(lastChar))
        lastChar = getchar();

    // Identifier token or keyword
    if (isalpha(lastChar)) {
        std::string idStr = lastChar;
        while (isalnum((lastChar = getchar())))
            idStr += lastChar;

        token_t idType;
        if (idStr == "def")
            idType = TOKEN_DEFINE;
        else if (idStr == "extern")
            idType = TOKEN_EXTERN;
        else
            idType = TOKEN_IDENTIFIER;

        return {idType, idStr, 0.0};
    }

    // Numerical token
    if (isdigit(lastChar) || lastChar == '.') {
        std::string numStr;
        do {
            numStr += lastChar;
            lastChar = getchar();
        } while (isdigit(lastChar) || lastChar == '.');

        double numVal = strtod(numStr.c_str(), 0);
        return {TOKEN_NUMBER, "", numVal};
    }

    if (lastChar == '#') {
        // Comment until end of line.
        do
            lastChar = getchar();
        while (lastChar != EOF && lastChar != '\n' && lastChar != '\r');

        if (lastChar != EOF)
            return getToken();
    }

    if (lastChar == EOF)
        return {TOKEN_EOF, "", 0.0};
    
    int thisChar = lastChar;
    lastChar = getchar();
    return {TOKEN_ERROR, "", (double)thisChar};
}