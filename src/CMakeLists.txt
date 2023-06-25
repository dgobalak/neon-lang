set(SW_LIB_BINARY ${CMAKE_PROJECT_NAME}_sw_lib)

add_library(${SW_LIB_BINARY}
    ${PROJECT_SOURCE_DIR}/src/compiler.cpp
    ${PROJECT_SOURCE_DIR}/src/lexer.cpp
)

target_include_directories(${SW_LIB_BINARY} PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)
