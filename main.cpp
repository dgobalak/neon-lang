#include <iostream>

#include "compiler.hpp"
#include "err_codes.hpp"
#include "scanner.hpp"
#include "spdlog/spdlog.h"

int main(int argc, char* argv[]) {
  neon_err_code_E neon_err{neon_err_code_E::ERROR_CODE_SUCCESS};

  // TODO: Implement logging setup
  spdlog::set_level(spdlog::level::debug);

  // TODO: Work on cmd line arg parsing
  if (argc != 3) {
    spdlog::error("Usage: {} <input_file_path> <output_file_path>", argv[0]);
    return 1;
  }

  const std::string input_file_path{argv[1]};
  const std::string output_file_path{argv[2]};

  FileScanner fscan{input_file_path};

  std::string file_contents{fscan.getContents()};
  spdlog::debug("File contents: {}", file_contents);

  Compiler compiler{};
  neon_err = compiler.compile(input_file_path, output_file_path);
  if (neon_err != neon_err_code_E::ERROR_CODE_SUCCESS) {
    spdlog::error("Error compiling {}: {}", input_file_path,
                  static_cast<int>(neon_err));
    return 1;
  }

  return 0;
}
