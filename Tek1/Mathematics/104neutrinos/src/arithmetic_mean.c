/*
** EPITECH PROJECT, 2024
** 104neutrinos
** File description:
** 104neutrinos nb_values
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include "my.h"
#include "my_macro.h"

int disp_arithmetic_mean(double *arithmetic_mean, int value_given, int n)
{
    *arithmetic_mean = ((*arithmetic_mean) * (n - 1) + value_given) / n;
    printf("    Arithmetic mean: %0.2f\n", *arithmetic_mean);
    return 0;
}
