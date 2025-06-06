/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** Prints any integer.
*/

#include "my_lib.h"

static int cut_number(int nb)
{
    if (nb == -2147483648) {
        my_putchar('-');
        my_putstr("2147483648");
        return 0;
    }
    if (nb < 0) {
        my_putchar('-');
        cut_number(- nb);
        return (0);
    }
    if (nb <= 9) {
        my_putchar(nb + 48);
        return (0);
    }
    cut_number(nb / 10);
    cut_number(nb % 10);
    return (0);
}

int my_put_nbr(int nb)
{
    cut_number(nb);
    return (0);
}
