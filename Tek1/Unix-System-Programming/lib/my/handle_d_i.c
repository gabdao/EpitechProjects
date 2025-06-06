/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** Handle d and i
*/

#include "../../include/my.h"
#include <stdarg.h>
#include <stdio.h>
int handle_d_i(const char *format, int *i, va_list args)
{
    int value;

    if (format[*i - 1] == 'h' && format[*i - 2] == 'h') {
        value = (signed char)va_arg(args, int);
    } else if (format[*i - 1] == 'h') {
        value = (short int)va_arg(args, int);
    } else {
        value = va_arg(args, int);
    }
    my_put_nbr(value);
    return 0;
}
