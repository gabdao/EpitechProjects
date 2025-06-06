/*
** EPITECH PROJECT, 2024
** setting_up algorithme
** File description:
** Projet setting_up algorithme démineur inversé
*/

#include "my.h"
#include "my_macro.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static int get_dimensions(char **map, int *num_lines, int *num_columns)
{
    *num_lines = my_atoi(map[NB_OF_LINES_IN_FST_LINE]);
    *num_columns = my_strlen(map[LENGTH_OF_LINE]);
    return 0;
}

static int **create_dp_tab(int num_lines, int num_columns)
{
    int **dp = malloc(num_lines * sizeof(int *));

    for (int i = 0; i < num_lines; i++) {
        dp[i] = malloc(num_columns * sizeof(int));
    }
    return dp;
}

static int **start_dp_tab(int **dp, char **map, int num_lines, int num_columns)
{
    for (int i = 0; i < num_lines; i++) {
        if (map[i + 1][0] == '.') {
            dp[i][0] = 1;
        } else {
            dp[i][0] = 0;
        }
    }
    for (int j = 0; j < num_columns; j++) {
        if (map[1][j] == '.') {
            dp[0][j] = 1;
        } else {
            dp[0][j] = 0;
        }
    }
    return dp;
}

static int assign_dp_value(char **map, int **dp, int i, int j)
{
    if (map[i + 1][j] == '.') {
        dp[i][j] = my_min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
    } else {
        dp[i][j] = 0;
    }
    return dp[i][j];
}

static void fill_dp_tab(int **dp, char **map, int num_lines, int num_columns)
{
    for (int i = 1; i < num_lines; i++) {
        for (int j = 1; j < num_columns; j++) {
            assign_dp_value(map, dp, i, j);
        }
    }
}

static int mark_square(char **map, int i, int j)
{
    if (map[i][j] == '.') {
                map[i][j] = 'x';
            }
    return 0;
}

static void update_max_square(square_info_t *info, int i, int j)
{
    if (info->dp[i][j] > info->max_size) {
        info->max_size = info->dp[i][j];
        info->max_i = i;
        info->max_j = j;
    }
}

static void bigest_square(int **dp, char **map, int num_lines, int num_columns)
{
    square_info_t info = {dp, 0, 0, 0};

    for (int i = 1; i < num_lines; i++) {
        for (int j = 1; j < num_columns; j++) {
            update_max_square(&info, i, j);
        }
    }
    for (int i = info.max_i - info.max_size + 1; i <= info.max_i; i++) {
        for (int j = info.max_j - info.max_size + 1; j <= info.max_j; j++) {
            mark_square(map, i + 1, j);
        }
    }
    for (int i = 1; i < num_lines + 1; i++) {
        my_printf("%s\n", map[i]);
    }
}

int launching_algo(char **map)
{
    int num_lines = 0;
    int num_columns = 0;
    int **dp;

    get_dimensions(map, &num_lines, &num_columns);
    dp = create_dp_tab(num_lines, num_columns);
    dp = start_dp_tab(dp, map, num_lines, num_columns);
    fill_dp_tab(dp, map, num_lines, num_columns);
    bigest_square(dp, map, num_lines, num_columns);
    for (int i = 0; i < num_lines; i++) {
        free(dp[i]);
    }
    free(dp);
    return 0;
}
