#include <fstream>
#include <string>

#include "err_codes.hpp"
#include "scanner.hpp"

StringScanner::StringScanner(const std::string& str)
    : str_contents_{str}, str_pos_{0} {}

std::string StringScanner::getContents() { return str_contents_; }

char StringScanner::getNextChar() {
  if (str_pos_ >= str_contents_.size()) {
    return '\0';
  }

  return str_contents_[str_pos_++];
}
