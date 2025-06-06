/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** header for mylib
*/
#include <stdarg.h>
#ifndef MY_H
    #define MY_H

struct flags_and_functions {
    char flags;
    int (*function_ptr)(const char *format, int *i, va_list args);
};
int my_printf(const char *format, ...);
int handle_c(const char *format, int *i, va_list args);
int handle_s(const char *format, int *i, va_list args);
int handle_d_i(const char *format, int *i, va_list args);
int handle_u(const char *format, int *i, va_list args);
int handle_o(const char *format, int *i, va_list args);
int handle_x(const char *format, int *i, va_list args);
int handle_upcase_x(const char *format, int *i, va_list args);
int handle_p(const char *format, int *i, va_list args);
int handle_f(const char *format, int *i, va_list args);
int handle_up_f(const char *format, int *i, va_list args);
int handle_e(const char *format, int *i, va_list args);
int handle_up_e(const char *format, int *i, va_list args);
int count_decimals(double number);
void my_put_e(long double nb, int precision);
void my_put_up_e(long double nb, int precision);
int handle_up_e(const char *format, int *i, va_list args);
int handle_g(const char *format, int *i, va_list args);
int handle_n(const char *format, int *i, va_list args);
int handle_prct(const char *format, int *i, va_list args);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_strlen(char const *str);
int my_compute_power_rec(int nb, int power);
void my_putfloat(double nb, int decimals);
int my_putstr(char const *str);

#endif
