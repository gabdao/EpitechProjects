/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** Handle u
*/

#include "my_lib.h"
#include <stdio.h>

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

int handle_u(const char *format, int *i, va_list args)
{
    unsigned int number;

    if (format[*i - 1] == 'h' && format[*i - 2] == 'h') {
        number = (unsigned char)va_arg(args, unsigned int);
    } else if (format[*i - 1] == 'h') {
        number = (unsigned short)va_arg(args, unsigned int);
    } else {
        number = va_arg(args, unsigned int);
    }
    cut_unsigned_number(number);
    return 0;
}
