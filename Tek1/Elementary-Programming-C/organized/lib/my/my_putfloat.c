/*
** EPITECH PROJECT, 2024
** my_putfloat
** File description:
** printf a given float with precision
*/

#include "../../include/my.h"

static int is_over_six(int nbr)
{
    if (nbr > 6) {
        return 6;
    } else {
    return nbr;
    }
}

void is_printable(int nbr)
{
    if (nbr > 0.0000000000000000000000000000001)
        my_put_nbr(nbr);
}

void missing_zeroes_precision(int count, int decimals)
{
    while (count < decimals) {
        my_put_nbr(0);
        count++;
    }
}

void missing_zeroes_normal(int nbr)
{
    while (nbr < 6) {
        my_put_nbr(0);
        nbr++;
    }
}

int count_decimals(double number)
{
    int counted_pwr = 0;

    if (number < 0) {
        number = number * -1;
    }
    number = number - (int)number;
    while (number > 0.000000009) {
        number = number * 10;
        counted_pwr = counted_pwr + 1;
        number = number - (int)(float)number;
    }
    return counted_pwr;
}

void my_putfloat(double nb, int decimals)
{
    double precise_nb = nb + 0.00000000000000001;
    int nb_integer = (int) precise_nb;
    int nb_decimals = count_decimals(nb);

    if (decimals == -1) {
        nb_decimals = is_over_six(nb_decimals);
        nb_decimals = (int) ((precise_nb - nb_integer) *
        my_compute_power_rec(10, nb_decimals) + 0.5);
        my_put_nbr(nb_integer);
        my_putchar('.');
        is_printable(nb_decimals);
        missing_zeroes_normal(count_decimals(nb));
        return;
    }
    nb_decimals = (int) ((precise_nb - nb_integer) *
    my_compute_power_rec(10, decimals) + 0.5);
    my_put_nbr(nb_integer);
    my_putchar('.');
    my_put_nbr(nb_decimals);
    missing_zeroes_precision(count_decimals(nb), decimals);
}
