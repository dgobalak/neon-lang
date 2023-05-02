cmake_minimum_required(VERSION 3.0.0)
project(compiler LANGUAGES CXX)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

set(SOURCES
    main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
