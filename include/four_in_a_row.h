#ifndef FOUR_IN_A_ROW_H
#define FOUR_IN_A_ROW_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define ERROR -1

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
bool put_piece(char (*board)[(WIDTH + 1)], const int column, const int player);
void print_board(const char (*board)[(WIDTH + 1)]);

/* game.c */
int game_loop(char (*board)[(WIDTH + 1)], const bool is_player_1_first);

#endif