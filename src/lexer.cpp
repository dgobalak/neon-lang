#include "lexer.hpp"

#include <fstream>

#include "err_codes.hpp"

neon_err_code_E Lexer::lex(const std::string& fpath) {
  std::ifstream ifs(fpath);

  if (!ifs) {
    return neon_err_code_E::ERROR_CODE_LEXER_FILE_NOT_FOUND;
  }

  // Read the file byte by byte

  return neon_err_code_E::ERROR_CODE_SUCCESS;
}
