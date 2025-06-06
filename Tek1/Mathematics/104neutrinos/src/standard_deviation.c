/*
** EPITECH PROJECT, 2024
** 104neutrinos
** File description:
** 104neutrinos standard deviation
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include "my.h"
#include "my_macro.h"

int disp_stand_deviation(
    int value_given,
    int n,
    double *arithmetic_mean,
    double *sd)
{
    double mean_diff = value_given - *arithmetic_mean;
    double variance = (pow(*sd, 2) * (n - 1) + pow(mean_diff, 2)) / (n);

    *sd = sqrt(variance);
    printf("    Standard deviation: %.2f\n", *sd);
    return 0;
}
