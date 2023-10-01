#pragma once

#include <cstdint>
#include <string>

#include "err_codes.hpp"
class Lexer {
 public:
  Lexer() = default;
  ~Lexer() = default;
  Lexer(const Lexer& other) = delete;
  Lexer(Lexer&& other) = delete;
  Lexer& operator=(const Lexer& other) = delete;
  Lexer& operator=(Lexer&& other) = delete;

  neon_err_code_E lex(const std::string& fpath);
};

enum class token_type_E {
  TOKEN_NUMBER,
  TOKEN_WHITESPACE,
  TOKEN_IDENTIFIER,
  TOKEN_KEYWORD,
  TOKEN_OPERATOR,
  TOKEN_COMMENT,
  TOKEN_END_STATEMENT,
  TOKEN_EOF,
};

typedef struct token_S {
  token_type_E type;
  std::string value;
  uint32_t lineNum;
  uint32_t colNum;
};
