#include "compiler.hpp"

#include <iostream>

#include "err_codes.hpp"

neon_err_code_E Compiler::compile(const std::string& input_file_path,
                                  const std::string& output_file_path) {
  neon_err_code_E ret;

  ret = lexer_.lex(input_file_path);
  if (ret != neon_err_code_E::ERROR_CODE_SUCCESS) {
    return ret;
  }

  std::cout << "Compiling " << input_file_path << " to " << output_file_path
            << std::endl;

  return neon_err_code_E::ERROR_CODE_SUCCESS;
}
