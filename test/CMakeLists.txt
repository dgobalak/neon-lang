include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

set(BINARY ${CMAKE_PROJECT_NAME}_test)

set(TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_formula.cpp
)

# target_include_directories(${BINARY} PUBLIC
#     ${PROJECT_SOURCE_DIR}/include
# )

add_executable(${BINARY} ${TEST_SOURCES})

target_link_libraries(${BINARY}
    PRIVATE
    GTest::GTest
    ${CMAKE_PROJECT_NAME}
)

add_test(${BINARY} ${BINARY})
