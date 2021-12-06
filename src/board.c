#include "four_in_a_row.h"

void set_cell(char *board_cell, char set_ch)
{
    (*board_cell) = set_ch;
}

void init_board(char (*board)[(WIDTH + 1)])
{
    for (uint8_t h = 0; h < HEIGHT; h++)
    {
        for (uint8_t w = 0; w <= WIDTH; w++)
        {
            if (w == WIDTH)
                set_cell(&(board[h][w]), NUL);
            else
                set_cell(&(board[h][w]), EMPTY);
        }
    }
}
