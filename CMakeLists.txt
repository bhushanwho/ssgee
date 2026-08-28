cmake_minimum_required(VERSION 3.20)

project(ssgee
    VERSION 0.1.0
    LANGUAGES CXX
)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(ssgee 
    src/main.cpp
)

target_compile_options(ssgee PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)