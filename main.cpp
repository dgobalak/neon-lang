#include <iostream>

#include "compiler.hpp"
#include "err_codes.hpp"
#include "spdlog/spdlog.h"

int main(int argc, char* argv[]) {
  Compiler compiler{};

  if (argc != 3) {
    spdlog::error("Usage: {} <input_file_path> <output_file_path>", argv[0]);
    return 1;
  }

  const std::string input_file_path{argv[1]};
  const std::string output_file_path{argv[2]};

  const ErrorCode error_code{
      compiler.compile(input_file_path, output_file_path)};
  if (error_code != ErrorCode::ERROR_CODE_SUCCESS) {
    spdlog::error("Error compiling {}: {}", input_file_path,
                  static_cast<int>(error_code));
    return 1;
  }

  return 0;
}
