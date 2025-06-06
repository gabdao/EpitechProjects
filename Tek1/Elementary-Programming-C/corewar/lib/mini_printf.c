/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** mini_printf
*/

#include <stdio.h>
#include <stdarg.h>
#include "my_lib_functions.h"

int flags(const char *format, int i, va_list args)
{
    switch (format[i + 1]) {
    case 'd':
        my_put_nbr(va_arg(args, int));
        break;
    case 'i':
        my_put_nbr(va_arg(args, int));
        break;
    case 's':
        my_putstr(va_arg(args, char *));
        break;
    case 'c':
        my_putchar((char) va_arg(args, int));
        break;
    case '%':
        my_putchar('%');
        break;
    }
}

void mini_printf(const char *format, ...)
{
    int i = 0;
    va_list args;

    va_start(args, format);
    for (; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            flags(format, i, args);
            i++;
        } else {
            my_putchar(format[i]);
        }
    }
    va_end(args);
}
