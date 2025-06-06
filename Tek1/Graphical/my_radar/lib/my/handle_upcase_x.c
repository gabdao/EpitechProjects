/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** Handle X
*/

#include "my_lib.h"
int cut_upcase_x_number(unsigned int nb)
{
    if (nb < 16) {
        if (nb < 10)
            my_putchar(nb + '0');
        else
            my_putchar(nb - 10 + 'A');
        return 0;
    }
    cut_upcase_x_number(nb / 16);
    if (nb % 16 < 10)
        my_putchar((nb % 16) + 48);
    else
        my_putchar((nb % 16) - 10 + 'A');
    return 0;
}

int handle_upcase_x(const char *format, int *i, va_list args)
{
    unsigned int number;

    if (format[*i - 1] == 'h' && format[*i - 2] == 'h') {
        number = (unsigned char)va_arg(args, unsigned int);
    } else if (format[*i - 1] == 'h') {
        number = (unsigned short)va_arg(args, unsigned int);
    } else {
        number = va_arg(args, unsigned int);
    }
    cut_upcase_x_number(number);
    return 0;
}
