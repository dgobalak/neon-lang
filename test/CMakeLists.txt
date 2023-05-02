set(TEST_BINARY ${CMAKE_PROJECT_NAME}_test)
set(SW_LIB_BINARY ${CMAKE_PROJECT_NAME}_sw_lib)

set(TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test_formula.cpp
)

add_executable(${TEST_BINARY} ${TEST_SOURCES})

target_link_libraries(${TEST_BINARY}
    PRIVATE
    GTest::GTest
    ${SW_LIB_BINARY}
)

add_test(${TEST_BINARY} ${TEST_BINARY})
