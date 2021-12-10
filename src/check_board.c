#include "four_in_a_row.h"

static bool check_upper_left(const char (*board)[(WIDTH + 1)], const int column, const int row)
{
    int piece;
    int count;
    int w;
    int h;

    count = 0;
    w = column;
    h = row;
    piece = board[row][column];
    while (w > 0 && h < (HEIGHT - 1))
    {
        if (board[h + 1][w - 1] != piece)
            break;
        w -= 1;
        h += 1;
    }
    while (w < WIDTH && h >= 0)
    {
        if (board[h][w] != piece)
            return (false);
        count += 1;
        if (count >= GOAL)
            return (true);
        w += 1;
        h -= 1;
    }
    return (false);
}

static bool check_lower_left(const char (*board)[(WIDTH + 1)], const int column, const int row)
{
    int piece;
    int count;
    int w;
    int h;

    count = 0;
    w = column;
    h = row;
    piece = board[row][column];
    while (w > 0 && h > 0)
    {
        if (board[h - 1][w - 1] != piece)
            break;
        w -= 1;
        h -= 1;
    }
    while (w < WIDTH && h < HEIGHT)
    {
        if (board[h][w] != piece)
            return (false);
        count += 1;
        if (count >= GOAL)
            return (true);
        w += 1;
        h += 1;
    }
    return (false);
}

bool check_diagonal(const char (*board)[(WIDTH + 1)], const int column, const int row)
{
    if (check_upper_left(board, column, row))
        return (true);
    if (check_lower_left(board, column, row))
        return (true);
    return (false);
}

bool check_vertical(const char (*board)[(WIDTH + 1)], const int column, const int row)
{
    int piece;
    int count;
    int h;

    piece = board[row][column];
    h = row;
    count = 0;
    while (h < HEIGHT && board[h][column] == piece)
    {
        count += 1;
        h += 1;
    }
    if (count >= GOAL)
        return (true);
    return (false);
}

bool check_horizontal(const char (*board)[(WIDTH + 1)], const int column, const int row)
{
    int piece;
    int count;
    int w;

    count = 1;
    piece = board[row][column];
    for (int w = column; w > 0; w--)
    {
        if (board[row][w - 1] != piece)
            break;
        count += 1;
    }
    for (int w = column; w < (WIDTH - 1); w++)
    {
        if (board[row][w + 1] != piece)
            break;
        count += 1;
    }
    if (count >= GOAL)
        return (true);
    return (false);
}
