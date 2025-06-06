/*
** EPITECH PROJECT, 2024
** 104neutrinos
** File description:
** 104neutrinos harmonic mean
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include "my.h"
#include "my_macro.h"

int disp_harmonic_mean(int value_given, int *n, double *harmonic_mean)
{
    double updated_harmonic_sum;

    updated_harmonic_sum = (*n / *harmonic_mean) + (1.0 / value_given);
    *harmonic_mean = (*n + 1) / updated_harmonic_sum;
    printf("    Harmonic mean: %.2f\n", *harmonic_mean);
    return 0;
}
