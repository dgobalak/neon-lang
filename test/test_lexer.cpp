#include <gtest/gtest.h>

#include "lexer.h"

TEST(TestLexer, InvalidFilePath) {
  Lexer lexer;
  const std::string invalid_file_path = "this/is/an/invalid/file/path";
  EXPECT_EQ(lexer.lex(invalid_file_path),
            ErrorCode::ERROR_CODE_LEXER_FILE_NOT_FOUND);
}
