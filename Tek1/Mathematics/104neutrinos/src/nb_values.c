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

int disp_nb_values(int *n)
{
    (*n)++;
    printf("    Number of values: %d\n", *n);
    return 0;
}
