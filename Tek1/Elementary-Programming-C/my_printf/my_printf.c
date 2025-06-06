/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** Function that imitates the printf function
*/
#include <stdio.h>
#include <stdarg.h>
#include "./include/my.h"

const struct flags_and_functions table[] = {
    {'c', handle_c},
    {'s', handle_s},
    {'d', handle_d_i},
    {'i', handle_d_i},
    {'u', handle_u},
    {'o', handle_o},
    {'x', handle_x},
    {'X', handle_upcase_x},
    {'p', handle_p},
    {'f', handle_f},
    {'F', handle_up_f},
    {'e', handle_e},
    {'E', handle_up_e},
    {'g', handle_g},
    {'G', handle_g},
    {'n', handle_n},
    {'%', handle_prct},
};

int inside_loop(int i, const char *format, va_list args)
{
    for (int y = 0; y < 17; y++) {
        if (format[i] == table[y].flags) {
            table[y].function_ptr(format, &i, args);
            break;
        }
    }
    return 0;
}

int handle_length_modifiers(const char *format, int i)
{
    if (format[i] == 'h' && format[i + 1] == 'h') {
        return i + 2;
    }
    if (format[i] == 'l' && format[i + 1] == 'l') {
        return i + 2;
    }
    if (format[i] == 'h' || format[i] == 'l' ||
    format[i] == 'z' || format[i] == 't') {
    return i + 1;
    }
    return i;
}

int my_printf(const char *format, ...)
{
    va_list args;

    va_start(args, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] != '\0') {
            i++;
            i = handle_length_modifiers(format, i);
            inside_loop(i, format, args);
        } else {
            my_putchar(format[i]);
        }
    }
    va_end(args);
    return 0;
}
