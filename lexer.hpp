#pragma once

#include <string>
#include <tuple>

typedef enum {
    TOKEN_EOF,
    TOKEN_DEFINE,
    TOKEN_EXTERN,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_ERROR,
} token_t;

typedef std::tuple<token_t, std::string, double> token_holder_t;

token_holder_t getToken();