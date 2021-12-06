#include "four_in_a_row.h"

static void set_cell(char *board_cell, char set_ch)
{
    (*board_cell) = set_ch;
}

static char get_piece(const int player)
{
    char piece;

    if (player == PLAYER_1)
        piece = PIECE_1;
    else if (player == PLAYER_2)
        piece = PIECE_2;
    else
        piece = UNKNOWN;
    return (piece);
}

void init_board(char (*board)[(WIDTH + 1)])
{
    for (int h = 0; h < HEIGHT; h++)
    {
        for (int w = 0; w <= WIDTH; w++)
        {
            if (w == WIDTH)
                set_cell(&(board[h][w]), NUL);
            else
                set_cell(&(board[h][w]), EMPTY);
        }
    }
}

bool put_piece(char (*board)[(WIDTH + 1)], const int column, const int player)
{
    for (int h = (HEIGHT - 1); h >= 0; h--)
    {
        if (board[h][column] == EMPTY)
        {
            char piece;

            piece = get_piece(player);
            if (piece == UNKNOWN)
                return (false);
            set_cell(&(board[h][column]), piece);
            return (true);
        }
    }
    return (false);
}

void print_board(const char (*board)[(WIDTH + 1)])
{
    for (int h = 0; h < HEIGHT; h++)
    {
        printf("%s\n", board[h]);
    }
}
