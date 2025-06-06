/*
** EPITECH PROJECT, 2024
** my_compute_square_root
** File description:
** Recursive Function that returns the square root
*/
#include <stdio.h>
#include <unistd.h>
int my_compute_square_root(int nb)
{
    int i;
    int square_number;

    if (nb < 0) {
        return 0;
    }
    for (i = 0; i * i <= nb; i++) {
        if (i * i == nb) {
            return i;
        }
    }
    return 0;
}
