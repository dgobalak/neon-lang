#pragma once

#include <fstream>
#include <string>

#include "err_codes.hpp"

class FileScanner {
 public:
  FileScanner() = default;
  ~FileScanner();
  FileScanner(const FileScanner& other) = delete;
  FileScanner(FileScanner&& other) = delete;
  FileScanner& operator=(const FileScanner& other) = delete;
  FileScanner& operator=(FileScanner&& other) = delete;

  neon_err_code_E open(const std::string& fname);
  neon_err_code_E close();
  neon_err_code_E getNextChar(char& c);
  bool hasMoreChars();

 private:
  std::ifstream file_;
};
