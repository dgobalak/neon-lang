#pragma once

#include "err_codes.hpp"

class Ast {
 public:
  Ast() = default;
  ~Ast() = default;
  Ast(const Ast& other) = delete;
  Ast(Ast&& other) = delete;
  Ast& operator=(const Ast& rhs) = delete;
  Ast& operator=(Ast&& rhs) = delete;
};
