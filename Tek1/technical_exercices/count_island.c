/*
** EPITECH PROJECT, 2024
** count_island
** File description:
** Project
*/
#include <stdio.h>
#include "include/my.h"

char translate(int island_number)
{
    if (island_number == 0)
        return '0';
    if (island_number == 1)
        return '1';
    if (island_number == 2)
        return '2';
    if (island_number == 3)
        return '3';
    if (island_number == 4)
        return '4';
    if (island_number == 5)
        return '5';
    if (island_number == 6)
        return '6';
    if (island_number == 7)
        return '7';
    if (island_number == 8)
        return '8';
    if (island_number == 9)
        return '9';
}

int x_finder(char **world, int i, int j, int island_number)
{
    char translated;

    if (i < 0 || j < 0 || world[i] == NULL || world[i][j] == '\0')
        return 0;
    if (world[i][j] != 'X')
        return 0;
    if (world[i][j] == 'X') {
        translated = translate(island_number);
        world[i][j] = translated;
    }
    x_finder(world, i - 1, j, island_number);
    x_finder(world, i + 1, j, island_number);
    x_finder(world, i, j + 1, island_number);
    x_finder(world, i, j - 1, island_number);
    return 0;
}

void check_characters(char **world, int i, int *island_number)
{
    int j;

    for (j = 0; world[i][j] != '\0'; j++) {
        if (world[i][j] == 'X') {
            x_finder(world, i, j, *island_number);
            (*island_number)++;
        }
    }
}

int check_lines(char **world)
{
    int i;
    int island_number = 0;

    for (i = 0; world[i] != NULL; i++) {
        check_characters(world, i, &island_number);
    }
    return island_number;
}

int count_island(char **world)
{
    int island_number = check_lines(world);

    return island_number;
}
