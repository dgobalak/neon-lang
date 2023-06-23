#include <iostream>

#include "compiler.h"

int main(int argc, char* argv[]) {
  Compiler compiler{};

  if (argc != 3) {
    std::cout << "Usage: " << argv[0] << " <input_file_path> <output_file_path>"
              << std::endl;
    return 1;
  }

  const std::string input_file_path{argv[1]};
  const std::string output_file_path{argv[2]};

  const ErrorCode error_code{
      compiler.compile(input_file_path, output_file_path)};
  if (error_code != ErrorCode::ERROR_CODE_SUCCESS) {
    std::cout << "Error: " << static_cast<int>(error_code) << std::endl;
    return 1;
  }

  return 0;
}
