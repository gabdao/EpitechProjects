/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "my_lib_functions.h"

int my_put_nbr(int nb)
{
    int nb2;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 10) {
        nb2 = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(nb2 + 48);
    } else {
        my_putchar(nb + 48);
    }
    return 0;
}
