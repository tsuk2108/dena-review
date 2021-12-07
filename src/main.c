#include "four_in_a_row.h"

int main(void)
{
    char board[HEIGHT][WIDTH + 1];

    init_board(board);
    game_loop(board, true);

    return (0);
}