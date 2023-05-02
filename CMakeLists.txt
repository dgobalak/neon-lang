cmake_minimum_required(VERSION 3.16)
project(compiler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

add_subdirectory(src)
add_subdirectory(test)

# Check if build type contains "test" string
if (CMAKE_BUILD_TYPE MATCHES "test")
    add_test(NAME test COMMAND test)
    add_executable(test test.cpp)
    target_link_libraries(test PRIVATE src)
endif()
