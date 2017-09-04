#include "gtest/gtest.h"

const int DEAD_CELL = 0;
const int ALIVE_CELL = 1;

int game_board[6][6]  = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
};

int sizeOfBoard(int board[6][6]) {
    return sizeof(board[0]) / sizeof(board[0][0]);
}


int isCellAlive(int board[6][6], int row, int col) {

    int neighbourCount = 0;

    int rowMin = row-1 < 0 ? row : row-1;
    int rowMax = row+1 < sizeOfBoard(board) ? row+1 : row;
    int colMin = col-1 < 0 ? col : col-1;
    int colMax = col+1 < sizeOfBoard(board) ? col+1 : col;

    for (int i = rowMin; i <= rowMax; i++) {
        for (int j = colMin; j <= colMax; j++) {
            if ( board[i][j] != 0 && !(i == row && j == col) ) {
                neighbourCount++;
            }
        }
    }

    if ( neighbourCount == 3 ) return 1;
    if ( neighbourCount == 2 ) return board[row][col];
    if ( neighbourCount > 3 || neighbourCount < 2 ) return 0;

    return 2;
}


TEST(is_cell_alive, cell_will_die_if_has_fewer_than_two_neighbour){
    int temp_board[6][6];
    std::copy(&game_board[0][0], &game_board[0][0]+6*6, &temp_board[0][0]);
    int is_alive = isCellAlive(game_board, 0, 0);
    EXPECT_EQ(DEAD_CELL, is_alive);
}

TEST(is_cell_alive, cell_born_if_has_three_neighbors) {

    int temp_board[6][6];
    std::copy(&game_board[0][0], &game_board[0][0]+6*6, &temp_board[0][0]);
    temp_board[0][1] = 1;
    temp_board[1][0] = 1;
    temp_board[1][1] = 1;

    EXPECT_EQ(ALIVE_CELL, isCellAlive(temp_board, 0, 0));
}

TEST(is_cell_alive, test_cell_born_if_has_three_neighbour_right_bottom_corner) {

    int temp_board[6][6];
    std::copy(&game_board[0][0], &game_board[0][0]+6*6, &temp_board[0][0]);

    temp_board[4][4] = 1;
    temp_board[4][5] = 1;
    temp_board[5][4] = 1;

    EXPECT_EQ(ALIVE_CELL, isCellAlive(temp_board, 5, 5));

}


TEST(is_cell_alive, test_cell_die_if_has_more_than_three_neighbour_right_edge_of_board) {

    int temp_board[6][6];
    std::copy(&game_board[0][0], &game_board[0][0]+6*6, &temp_board[0][0]);

    temp_board[3][0] = 1;
    temp_board[3][1] = 1;
    temp_board[4][1] = 1;
    temp_board[5][0] = 1;
    temp_board[5][1] = 1;

    EXPECT_EQ(DEAD_CELL, isCellAlive(temp_board, 4, 0));

}

TEST(is_cell_alive, test_cell_die_if_has_more_than_three_neighbour_left_edge_of_board) {

    int temp_board[6][6];
    std::copy(&game_board[0][0], &game_board[0][0]+6*6, &temp_board[0][0]);

    temp_board[1][5] = 1; //cell is living

    temp_board[0][4] = 1;
    temp_board[0][5] = 1;
    temp_board[1][4] = 1;
    temp_board[2][4] = 1;

    EXPECT_EQ(DEAD_CELL, isCellAlive(temp_board, 4, 0));
}

TEST(is_cell_alive, test_cell_lives_if_has_three_neighbour_middle_of_board) {
    int temp_board[6][6];
    std::copy(&game_board[0][0], &game_board[0][0]+6*6, &temp_board[0][0]);

    temp_board[2][2] = 1; //cell is living

    temp_board[1][1] = 1;
    temp_board[1][2] = 1;
    temp_board[2][1] = 1;

    EXPECT_EQ(ALIVE_CELL, isCellAlive(temp_board, 2, 2));

}

TEST(is_cell_alive, test_cell_lives_if_has_two_neighbour_middle_of_board) {
    int temp_board[6][6];
    std::copy(&game_board[0][0], &game_board[0][0]+6*6, &temp_board[0][0]);

    temp_board[2][2] = 1; //cell is living

    temp_board[1][1] = 1;
    temp_board[1][2] = 1;

    EXPECT_EQ(ALIVE_CELL, isCellAlive(temp_board, 2, 2));

}


