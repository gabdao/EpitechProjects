/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** Prints any integer.
*/

#include "my_lib.h"

static int cut_unsigned_number(unsigned int nb)
{
    if (nb < 0) {
        my_putchar('-');
        cut_unsigned_number(- nb);
        return (0);
    }
    if (nb <= 9) {
        my_putchar(nb + 48);
        return (0);
    }
    cut_unsigned_number(nb / 10);
    cut_unsigned_number(nb % 10);
    return (0);
}

int my_put_unsigned_nbr(unsigned int nb)
{
    cut_unsigned_number(nb);
    return (0);
}
