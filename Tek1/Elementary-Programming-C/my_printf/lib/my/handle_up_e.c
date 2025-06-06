/*
** EPITECH PROJECT, 2024
** handle up e
** File description:
** handle the flag E of printf
*/

#include "../../include/my.h"

int handle_up_e(const char *format, int *i, va_list args)
{
    double nb = va_arg(args, double);

    my_put_up_e(nb, -1);
}
