cmake_minimum_required(VERSION 3.8)
project(game_of_life_cpp)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
add_executable(game_of_life_cpp ${SOURCE_FILES})