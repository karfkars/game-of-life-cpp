include_directories(${PROJECT_SOURCE_DIR}/game)

add_subdirectory(lib/googletest)

add_executable(game_of_life_test game_test.cpp)

target_link_libraries(game_of_life_test gtest gtest_main)
target_link_libraries(game_of_life_test game_of_life_source)