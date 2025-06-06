/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** Handle s
*/

#include "my_lib.h"
#include <stdio.h>

int handle_s(const char *format, int *i, va_list args)
{
    char *str = va_arg(args, char *);

    my_putstr(str);
    return 1;
}
