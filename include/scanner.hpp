#pragma once

#include <string>

#include "err_codes.hpp"

class ScannerInterface {
 public:
  virtual ~ScannerInterface() = default;
  virtual std::string getContents() = 0;
  virtual char getNextChar() = 0;
};

class FileScanner : public ScannerInterface {
 public:
  FileScanner() = delete;
  FileScanner(const std::string& fpath);
  ~FileScanner() = default;
  FileScanner(const FileScanner& other) = delete;
  FileScanner(FileScanner&& other) = delete;
  FileScanner& operator=(const FileScanner& other) = delete;
  FileScanner& operator=(FileScanner&& other) = delete;

  std::string getContents();
  char getNextChar();

 private:
  std::string file_contents_;
  std::string file_path_;
  size_t file_pos_;
};

class StringScanner : public ScannerInterface {
 public:
  StringScanner() = delete;
  StringScanner(const std::string& str);
  ~StringScanner() = default;
  StringScanner(const StringScanner& other) = delete;
  StringScanner(StringScanner&& other) = delete;
  StringScanner& operator=(const StringScanner& other) = delete;
  StringScanner& operator=(StringScanner&& other) = delete;

  std::string getContents();
  char getNextChar();

 private:
  std::string str_contents_;
  size_t str_pos_;
};
