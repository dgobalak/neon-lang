#include "compiler.h"

#include <iostream>

#include "err_codes.h"

ErrorCode Compiler::compile(const std::string& input_file_path,
                            const std::string& output_file_path) {
  ErrorCode ret;

  ret = lexer_.lex(input_file_path);
  if (ret != ErrorCode::ERROR_CODE_SUCCESS) {
    return ret;
  }

  std::cout << "Compiling " << input_file_path << " to " << output_file_path
            << std::endl;

  return ErrorCode::ERROR_CODE_SUCCESS;
}