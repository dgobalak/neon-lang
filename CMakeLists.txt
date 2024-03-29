cmake_minimum_required(VERSION 3.16)
project(compiler LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (CMAKE_BUILD_TYPE MATCHES "Test")
    # ---------------------------------------------------------------
    # Fetch GTest from github
    # ---------------------------------------------------------------
    include(FetchContent)

    FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.11.0
    )
    FetchContent_MakeAvailable(googletest)
    add_library(GTest::GTest INTERFACE IMPORTED)
    target_link_libraries(GTest::GTest INTERFACE gtest_main)
    # ---------------------------------------------------------------

    enable_testing()
endif()

add_subdirectory(src)

if (CMAKE_BUILD_TYPE MATCHES "Test")
    add_subdirectory(test)
endif()

if(CMAKE_BUILD_TYPE MATCHES "Neon")
    set(SW_BINARY ${CMAKE_PROJECT_NAME}_sw)
    add_executable(${SW_BINARY}
        main.cpp
    )

    add_subdirectory("${CMAKE_SOURCE_DIR}/libs/spdlog")

    target_link_libraries(${SW_BINARY} PRIVATE ${SW_BINARY}_lib)
    target_link_libraries(${SW_BINARY} PRIVATE spdlog::spdlog)
endif()
