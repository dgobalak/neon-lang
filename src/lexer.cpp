#include "lexer.h"

#include <fstream>

#include "err_codes.h"

ErrorCode Lexer::lex(const std::string& fpath) {
  std::ifstream ifs(fpath);

  if (!ifs) {
    return ErrorCode::ERROR_CODE_LEXER_FILE_NOT_FOUND;
  }

  // Read the file byte by byte

  return ErrorCode::ERROR_CODE_SUCCESS;
}
