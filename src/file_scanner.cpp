#include <fstream>
#include <string>

#include "err_codes.hpp"
#include "scanner.hpp"

FileScanner::FileScanner(const std::string& fpath)
    : file_path_{fpath}, file_pos_{0}, file_contents_{""} {}

std::string FileScanner::getContents() {
  if (!file_contents_.empty()) {
    return file_contents_;
  }

  std::ifstream ifs{file_path_};
  if (!ifs) {
    return "";
  }

  std::string line;
  while (std::getline(ifs, line)) {
    file_contents_ += line;
  }

  return file_contents_;
}

char FileScanner::getNextChar() {
  if (file_pos_ >= file_contents_.size()) {
    return '\0';
  }

  return file_contents_[file_pos_++];
}
