#include "fscanner.hpp"

#include <fstream>
#include <string>

#include "err_codes.hpp"

FileScanner::~FileScanner() {
  if (file_.is_open()) {
    file_.close();
  }
}

neon_err_code_E FileScanner::open(const std::string& fname) {
  file_.open(fname, std::ios::in);
  if (!file_.is_open()) {
    return neon_err_code_E::ERROR_CODE_FILE_NOT_FOUND;
  }
  return neon_err_code_E::ERROR_CODE_SUCCESS;
}

neon_err_code_E FileScanner::close() {
  if (file_.is_open()) {
    file_.close();
  }
  return neon_err_code_E::ERROR_CODE_SUCCESS;
}

bool FileScanner::hasMoreChars() {
  if (!file_.is_open()) {
    return false;
  }

  return !file_.eof();
}

neon_err_code_E FileScanner::getNextChar(char& c) {
  if (!file_.is_open()) {
    return neon_err_code_E::ERROR_CODE_FILE_NOT_OPEN;
  }

  if (file_.eof()) {
    return neon_err_code_E::ERROR_CODE_EOF_REACHED;
  }

  file_.get(c);
  if (file_.fail() && !file_.eof()) {
    return neon_err_code_E::ERROR_CODE_FILE_READ;
  }

  return neon_err_code_E::ERROR_CODE_SUCCESS;
}
