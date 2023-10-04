#include "lexer.hpp"

#include <iostream>

#include "err_codes.hpp"
#include "fscanner.hpp"

neon_err_code_E Lexer::lex(const std::string& fpath) {
  neon_err_code_E ret;

  FileScanner fscan{};

  ret = fscan.open(fpath);
  if (ret != neon_err_code_E::ERROR_CODE_SUCCESS) {
    return ret;
  }

  char c;
  while (fscan.hasMoreChars()) {
    ret = fscan.getNextChar(c);
    if (ret != neon_err_code_E::ERROR_CODE_SUCCESS) {
      return ret;
    }

    std::cout << c;
  }

  return neon_err_code_E::ERROR_CODE_SUCCESS;
}
