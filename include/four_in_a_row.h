#ifndef FOUR_IN_A_ROW_H
#define FOUR_IN_A_ROW_H

#include <stdio.h>
#include <stdbool.h>

#define WIDTH 7
#define HEIGHT 6

#define PLAYER_1 1
#define PLAYER_2 2

#define PIECE_1 'o'
#define PIECE_2 'x'
#define EMPTY '.'
#define UNKNOWN '?'
#define NUL '\0'

/* board.c */
void init_board(char (*board)[(WIDTH + 1)]);
bool put_piece(char (*board)[(WIDTH + 1)], int column, int player);
void print_board(const char (*board)[(WIDTH + 1)]);

#endif