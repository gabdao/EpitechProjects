/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** Handle o
*/

#include "../../include/my.h"

int cut_octal_number(unsigned int nb)
{
    if (nb < 0) {
        my_putchar('-');
        cut_octal_number(- nb);
        return (0);
    }
    if (nb <= 9) {
        my_putchar(nb + 48);
        return (0);
    }
    cut_octal_number(nb / 8);
    cut_octal_number(nb % 8);
    return (0);
}

int handle_o(const char *format, int *i, va_list args)
{
    unsigned int number;

    if (format[*i - 1] == 'h' && format[*i - 2] == 'h') {
        number = (unsigned char)va_arg(args, unsigned int);
    } else if (format[*i - 1] == 'h') {
        number = (unsigned short)va_arg(args, unsigned int);
    } else {
        number = va_arg(args, unsigned int);
    }
    cut_octal_number(number);
    return 0;
}
