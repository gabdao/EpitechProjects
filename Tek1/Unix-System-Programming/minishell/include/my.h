/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** header for mylib
*/
#include <stdarg.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>
#ifndef MY_H
    #define MY_H
    #include <stdarg.h>
struct flags_my_ls {
    char flags;
    int (*function_ptr)(int argc, char *argv[], char **content);
};
struct flags_and_functions {
    char flags;
    int (*function_ptr)(const char *format, int *i, va_list args);
};
//Fonctions my_ls
int handle_my_ls_a(int argc, char *argv[], char **content);
int handle_my_ls_l(int argc, char *argv[], char **content);
int handle_my_ls_up_r(int argc, char *argv[], char **content);
int handle_my_ls_d(int argc, char *argv[], char **content);
int handle_my_ls_r(int argc, char *argv[], char **content);
int handle_my_ls_t(int argc, char *argv[], char **content);
int handle_my_ls_no_flags(int argc, char *argv[], char **content);
int errors_in_stderr_l(int argc, const char *content);
int print_rights(mode_t data_rights);
int print_owners(uid_t owner, gid_t group, nlink_t nb_links);
int print_data_size(off_t size);
int print_last_modification_date(time_t last_modification);
int print_files_names(const char *filename);
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
char **my_str_to_word_array_su(char const *str);
char *my_strdup(const char *src);
int my_free_array(char **array);
#endif /* MY_H */
