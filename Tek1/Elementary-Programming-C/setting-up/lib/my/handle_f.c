/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** Handle f
*/

#include "../../include/my.h"
#include <stdarg.h>

int error_cases_f(double test_subject)
{
    if (__builtin_isnanf(test_subject) != 0) {
        my_putstr("-nan");
        return 84;
    }
    if (__builtin_isfinite(test_subject) == 0) {
        my_putstr("inf");
        return 84;
    }
}

int handle_f(const char *format, int *i, va_list args)
{
    double num = va_arg(args, double);

    if (error_cases_f(num) == 84) {
        return 84;
    }
    my_putfloat(num, -1);
    return 0;
}
