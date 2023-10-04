#include <gtest/gtest.h>

#include "lexer.hpp"

TEST(TestLexer, InvalidFilePath) {
  const std::string invalid_file_path = "this/is/an/invalid/file/path";
  Lexer lexer{};

  EXPECT_NE(lexer.lex(invalid_file_path), neon_err_code_E::ERROR_CODE_SUCCESS);
}
