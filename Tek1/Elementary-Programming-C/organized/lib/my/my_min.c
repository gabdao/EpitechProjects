/*
** EPITECH PROJECT, 2024
** min
** File description:
** return min value from 3 args
*/

#include "../../include/my.h"

int my_min(int a, int b, int c)
{
    int min_val = a;

    if (b < min_val) {
        min_val = b;
    }
    if (c < min_val) {
        min_val = c;
    }
    return min_val;
}
