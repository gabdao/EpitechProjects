/*
** EPITECH PROJECT, 2024
** 104neutrinos
** File description:
** 104neutrinos root mean square
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include "my.h"
#include "my_macro.h"

double calculate_rms(
    int value_given,
    double *arithmetic_mean,
    double *sd,
    int n)
{
    double sum_of_squares = 0;
    double sd_square = pow(*sd, 2);
    double a_mean_square = pow(*arithmetic_mean, 2);

    sum_of_squares = (sd_square + a_mean_square) * n;
    sum_of_squares += pow(value_given, 2);
    return sqrt(sum_of_squares / (n + 1));
}
