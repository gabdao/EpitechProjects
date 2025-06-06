/*
** EPITECH PROJECT, 2024
** handles the flag upper case f
** File description:
** flag F
*/

#include "../../include/my.h"

int error_cases_up_f(double test_subject)
{
    if (__builtin_isnanf(test_subject) != 0) {
        my_putstr("-NAN");
        return 84;
    }
    if (__builtin_isfinite(test_subject) == 0) {
        my_putstr("INF");
        return 84;
    }
    return 0;
}

int handle_up_f(const char *format, int *i, va_list args)
{
    double num = va_arg(args, double);

    if (error_cases_up_f(num) == 84) {
    return 84;
    }
    my_putfloat(num, -1);
    return 0;
}
