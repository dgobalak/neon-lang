add_library(${CMAKE_PROJECT_NAME}
    ${PROJECT_SOURCE_DIR}/src/formula.cpp
)

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)
