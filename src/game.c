#include "four_in_a_row.h"

static char *input_line(void)
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

static int convert_line_to_column(const char *line)
{
    int column;

    column = strtol(line, NULL, 10);
    if (column <= 0 || column > WIDTH)
        return (ERROR);
    return ((column - 1));
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
    int column;

    while (1)
    {
        char *line;
        line = input_line();
        column = convert_line_to_column(line);
        free(line);
        if (column == ERROR)
            continue;
        if (put_piece(board, column, player))
            break;
    }
    return (column);
}

static void update_display(void)
{
#ifdef _WIN64
    system("cls");
#elif _WIN32
    system("cls");
#else
    system("clear");
#endif
}

static void print_info(const int player_id)
{
    printf("[player%d turn]\n", player_id);
    for (int i = 1; i <= WIDTH; i++)
        printf("%d", i);
    printf("\n");
}

static void print_start_turn(const char (*board)[(WIDTH + 1)], const int player_id)
{
    update_display();
    print_info(player_id);
    print_board(board);
}

static bool is_finish(const char (*board)[(WIDTH + 1)], const int column)
{
    int row;

    row = 0;
    for (int h = 0; h < HEIGHT; h++)
    {
        if (board[h][column] != EMPTY)
        {
            row = h;
            break;
        }
    }
    if (check_diagonal(board, column, row))
        return (true);
    if (check_vertical(board, column, row))
        return (true);
    if (check_horizontal(board, column, row))
        return (true);
    return (false);
}

static void print_end_game(const char (*board)[(WIDTH + 1)], const int winner)
{
    update_display();
    print_board(board);
    printf("[player%d win!]\n", winner);
}

void game_loop(char (*board)[(WIDTH + 1)], const bool is_player_1_first)
{
    int turn;
    int id;
    int put_column;

    turn = 1;
    if (is_player_1_first)
        id = PLAYER_1;
    else
        id = PLAYER_2;
    while (1)
    {
        print_start_turn(board, id);
        if ((turn % 2) == is_player_1_first)
            put_column = player_turn(board, PLAYER_1);
        else
            put_column = player_turn(board, PLAYER_2);
        if (is_finish(board, put_column))
            break;
        id = next_player(id);
        turn += 1;
    }
    print_end_game(board, id);

    char ch;
    printf("Press enter...");
    scanf("%c", &ch);
}