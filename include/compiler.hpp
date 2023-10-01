#pragma once

#include <string>

#include "err_codes.hpp"
#include "lexer.hpp"

class Compiler {
 public:
  Compiler() = default;
  ~Compiler() = default;
  Compiler(const Compiler& other) = delete;
  Compiler& operator=(const Compiler& other) = delete;

  ErrorCode compile(const std::string& input_file_path,
                    const std::string& output_file_path);

 private:
  Lexer lexer_;
};
