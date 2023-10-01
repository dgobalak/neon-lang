#pragma once

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

  ErrorCode lex(const std::string& fpath);
};

enum class Token {

};
