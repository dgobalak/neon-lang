cmake_minimum_required(VERSION 3.16)
project(compiler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Check if build type contains "test" string
if (CMAKE_BUILD_TYPE MATCHES "Test")
    enable_testing()
    add_subdirectory(src)
    add_subdirectory(test)
elseif(CMAKE_BUILD_TYPE MATCHES "Software")
    set(BINARY ${CMAKE_PROJECT_NAME}_bin)
    add_executable(${BINARY} main.cpp)
    target_include_directories(${BINARY} PRIVATE include)
    add_subdirectory(src)
    target_link_libraries(${BINARY} PRIVATE ${CMAKE_PROJECT_NAME})
endif()
