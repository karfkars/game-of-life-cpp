add_subdirectory(lib/googletest)

add_executable(game_test game_test.cpp)

target_link_libraries(game_test gtest gtest_main)