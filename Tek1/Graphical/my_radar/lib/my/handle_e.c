/*
** EPITECH PROJECT, 2024
** handle e
** File description:
** handle the flag e
*/

#include "my_lib.h"

int handle_e(const char *format, int *i, va_list args)
{
    double nb = va_arg(args, double);

    my_put_e(nb, -1);
    return 0;
}
