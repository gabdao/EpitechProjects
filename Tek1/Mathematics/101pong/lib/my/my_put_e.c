/*
** EPITECH PROJECT, 2024
** my_put_e
** File description:
** puts a float into scientific notation
*/

#include "../../include/my.h"

void put_e_neg(long double nb, int precision)
{
    int count = 0;

    while (nb > 9) {
        nb = nb / 10;
        count++;
    }
    my_putfloat(nb, precision);
    my_putstr("e+");
    if (count < 10)
        my_put_nbr(0);
    my_put_nbr(count);
}

void put_e_pos(long double nb, int precision)
{
    int count = 0;

    while (nb < 1) {
        nb = nb * 10;
        count++;
    }
    my_putfloat(nb, precision);
    my_putstr("e-");
    if (count < 10)
        my_put_nbr(0);
    my_put_nbr(count);
}

void my_put_e(long double nb, int precision)
{
    if (nb >= 10) {
        put_e_neg(nb, precision);
    } else if (nb < 1) {
        put_e_pos(nb, precision);
    } else {
        my_putfloat(nb, precision);
        my_putstr("e+");
        my_put_nbr(00);
    }
}
