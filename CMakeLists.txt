cmake_minimum_required(VERSION 3.8)
project(game_of_life_cpp)

add_subdirectory(game)
add_subdirectory(game_test)

set(SOURCE_FILES main.cpp)

add_executable(game_of_life_cpp ${SOURCE_FILES})

set(CMAKE_CXX_STANDARD 14)