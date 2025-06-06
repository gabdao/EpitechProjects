/*
** EPITECH PROJECT, 2024
** B-CPE-100-PAR-1-2-Cworkshoplib-raphael.varichon-dupre
** File description:
** functions_proto.h
*/

#ifndef FUNCTIONS_PROTO
    #define FUNCTIONS_PROTO
    #include <stdio.h>
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
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
int my_intcmp(int n1, int n2);
char *int_to_char(int key, int len);
int my_nbrlen(long long int nb);
float my_put_float(double nb);
char *my_strdup(char const *src);
long int get_char_file_size(char *file_name);
char **my_str_to_word_array(char *str, char *spt);
void mini_printf(const char *format, ...);
int my_free_array(char **array);
#endif /* FUNCTIONS_PROTO */
