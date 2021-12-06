#include "four_in_a_row.h"

int main(void)
{
    char board[HEIGHT][WIDTH + 1];

    init_board(board);

    // test
    while (1)
    {
        print_board(board);
        int input;
        scanf("%d", &input);
        put_piece(board, (input - 1), PLAYER_1);
    }
    return (0);
}