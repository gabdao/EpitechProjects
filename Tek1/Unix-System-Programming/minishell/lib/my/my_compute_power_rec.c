/*
** EPITECH PROJECT, 2024
** my_compute_power_rec
** File description:
** Recursive Function that returns the first argumebt raised to the power
*/
#include <stdio.h>
#include <unistd.h>

int my_compute_power_rec(int nb, int p)
{
    if (p < 0) {
        return 0;
    }
    if (p == 0) {
        return 1;
    }
    return nb * my_compute_power_rec(nb, p - 1);
}
