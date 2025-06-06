/*
** EPITECH PROJECT, 2024
** handle_g
** File description:
** handles the flag g of printf
*/

#include "../../include/my.h"

static int prec_count(long double nb)
{
    int count = 0;

    while (nb > 9) {
        nb = nb / 10;
        count++;
    }
    return (count - 1);
}

int neg(long double nb, int precision)
{
    int count = 0;

    while (nb > 9) {
        nb = nb / 10;
        count++;
    }
    return count;
}

int pos(long double nb, int precision)
{
    int count = 0;

    while (nb < 1) {
        nb = nb * 10;
        count++;
    }
    return count;
}

void g_or_e(int x, int p, double nbr, int precision)
{
    if (p > x && x >= -4) {
        if (nbr - (int) nbr == 0) {
            my_put_nbr((int)nbr);
        } else {
            my_putfloat(nbr, precision);
        }
    } else {
        precision = prec_count(nbr);
        my_put_e(nbr, precision);
    }
}

int handle_g(const char *format, int *i, va_list args)
{
    double nbr = va_arg(args, double);
    int precision = count_decimals(nbr);
    int x;
    int p = 6;

    if (precision > 6)
        precision = 6;
    if (nbr >= 10) {
        x = neg(nbr, precision);
    } else if (nbr < 1) {
        x = pos(nbr, precision);
    } else {
        x = 0;
    }
    g_or_e(x, p, nbr, precision);
    return 0;
}
