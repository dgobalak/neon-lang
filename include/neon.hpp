#pragma once

#include <string>

#include "err_codes.hpp"
#include "lexer.hpp"

class Neon {
 public:
  Neon() = default;
  ~Neon() = default;
  Neon(Neon& other) = delete;
  Neon(Neon&& other) = delete;
  Neon& operator=(const Neon& other) = delete;
  Neon& operator=(Neon&& other) = delete;

  neon_err_code_E compile(const std::string& input_file_path,
                          const std::string& output_file_path);
};
