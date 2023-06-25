#pragma once

#include <string>

#include "err_codes.h"

class Lexer {
 public:
  Lexer() = default;
  ~Lexer() = default;
  Lexer(const Lexer& other) = delete;
  Lexer& operator=(const Lexer& other) = delete;

  ErrorCode lex(const std::string& fpath);
};

enum class Token {

};
