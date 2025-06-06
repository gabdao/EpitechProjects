/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** Handle c
*/

#include "../../include/my.h"
#include <stdio.h>
int handle_c(const char *format, int *i, va_list args)
{
    char c = va_arg(args, int);

    my_putchar(c);
    return 0;
}
