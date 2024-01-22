cmake_minimum_required(VERSION 3.22)

project(SDL_INPUT VERSION 0.1.0 DESCRIPTION "" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_compile_definitions($<$<CONFIG:Debug>:DEBUG>)
add_compile_definitions($<$<CONFIG:Release>:NDEBUG>)

include_directories(src C99)

find_package(SDL2 REQUIRED)

add_library(SDL_input SHARED
    src/SDL_input.cpp
    C99/SDL_input.c
)

target_compile_options(SDL_input
PRIVATE -Wall -Wextra -Werror
)
