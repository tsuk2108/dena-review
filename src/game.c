#include "four_in_a_row.h"

static char *input_line()
{
    char *line = NULL;
    size_t n = 0;

    printf("Select a column[%d ~ %d]:", 1, WIDTH);
    while (getline(&line, &n, stdin) == -1)
    {
        free(line);
        printf("Select a column[%d ~ %d]:", 1, WIDTH);
    }
    return (line);
}

static int convert_line_to_colmun(const char *line)
{
    int colmun;

    colmun = strtol(line, NULL, 10);
    if (colmun <= 0 || colmun > WIDTH)
        return (ERROR);
    return ((colmun - 1));
}

static int next_player(const int player)
{
    if (player == PLAYER_1)
        return (PLAYER_2);
    else if (player == PLAYER_2)
        return (PLAYER_1);
    else
        return (ERROR);
}

static int player_turn(char (*board)[(WIDTH + 1)], const int player)
{
    while (1)
    {
        int colmun;
        char *line;
        line = input_line();
        colmun = convert_line_to_colmun(line);
        free(line);
        if (colmun == ERROR)
            continue;
        if (put_piece(board, colmun, player))
            break;
    }
    return (next_player(player));
}

void print_info(const int player_id)
{
    printf("[player%d turn]\n", player_id);
    for (int i = 1; i <= WIDTH; i++)
        printf("%d", i);
    printf("\n");
}

void print_start_turn(const char (*board)[(WIDTH + 1)], const int player_id)
{
    print_info(player_id);
    print_board(board);
}

int game_loop(char (*board)[(WIDTH + 1)], const bool is_player_1_first)
{
    int turn;
    int id;

    turn = 1;
    if (is_player_1_first)
        id = PLAYER_1;
    else
        id = PLAYER_2;
    while (1)
    {
        system("cls");
        print_start_turn(board, id);
        if ((turn % 2) == is_player_1_first)
            id = player_turn(board, PLAYER_1);
        else
            id = player_turn(board, PLAYER_2);
        turn += 1;
    }
}