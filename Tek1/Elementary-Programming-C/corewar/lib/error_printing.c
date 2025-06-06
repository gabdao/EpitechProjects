/*
** EPITECH PROJECT, 2025
** error_printing
** File description:
** printing error on error output
*/

#include <stdio.h>
#include <unistd.h>

static int my_strlen(char *str)
{
    size_t count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        count++;
    }
    return count;
}

int print_error(char *str)
{
    write(2, str, my_strlen(str));
    return 0;
}
