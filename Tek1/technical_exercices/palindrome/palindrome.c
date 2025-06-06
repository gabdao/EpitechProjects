/*
** EPITECH PROJECT, 2025
** palindrome.c
** File description:
** palindrome
*/

#include <stddef.h>

int my_strlen(char *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        len++;
    }
    return len;
}

int check_palindrome(char *str)
{
    char *str_error = "not a palindrome.\n";
    char *str_success = "palindrome!\n";
    int len_error = my_strlen(str_error);
    int len_success = my_strlen(str_success);
    int len = my_strlen(str);
    int i = 0;

    while (i < len / 2) {
        if (str[i] != str[len - 1 - i]) {
            write(1, str_error, len_error);
            return 0;
        }
        i++;
    }
    write(1, str_success, len_success);
    return 0;
}

int check_args(int argc, char **argv)
{
    char *str_error = "Error: missing arguments.\n";
    int len_error = my_strlen(str_error);

    if (argc != 2) {
        write(2, str_error, len_error);
        return 84;
    }
    return 0;
}

char *handling_case_insensitive(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        } else
            str[i];
    }
    return str;
}

int main(int argc, char **argv)
{
    char *new_str = NULL;

    if (check_args(argc, argv) == 84) {
        return 84;
    }
    new_str = handling_case_insensitive(argv[1]);
    check_palindrome(new_str);
    return 0;
}
