#ifndef FOUR_IN_A_ROW_H
#define FOUR_IN_A_ROW_H

#include <stdint.h>

#define WIDTH 7
#define HEIGHT 6

#define EMPTY ' '
#define NUL '\0'

void init_board(char (*board)[(WIDTH + 1)]);
void set_cell(char *board_cell, char set_ch);

#endif