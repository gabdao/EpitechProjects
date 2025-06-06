/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** header for mylib
*/
#include <stdarg.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#ifndef MY_H_
    #define MY_H_

struct flags_and_functions {
    char flags;
    int (*function_ptr)(const char *format, int *i, va_list args);
};

char **my_str_to_word_array_su(char const *str);
//Fonctions pour setting up
int launching_algo(char **new_map);
int errors_handler(char *buffer_to_check);
int print_errors_messages(const char *message);
static int check_characters(char *buffer_to_check);
static int check_first_line_if_is_nb_lines(char *buffer);
static int check_lines_length(char *buffer);
static int check_if_different_line(int current_length, int line_len);
static int ignore_fst_line(char *buffer);
int my_is_digit(char c);
//Fonctions pour my_printf
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
void my_putfloat(double nb, int decimals);
void my_put_e(long double nb, int precision);
void my_put_up_e(long double nb, int precision);
int handle_up_e(const char *format, int *i, va_list args);
int handle_g(const char *format, int *i, va_list args);
int handle_n(const char *format, int *i, va_list args);
int handle_prct(const char *format, int *i, va_list args);
// Fonctions de la piscine
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
//Fonctions utiles
int my_is_digit(char c);
int my_atoi(char *str);
int my_min(int a, int b, int c);

#endif /* MY_H_ */
