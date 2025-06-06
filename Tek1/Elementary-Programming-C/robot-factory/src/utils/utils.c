/*
** EPITECH PROJECT, 2025
** main
** File description:
** main for robot factory
*/

#include "my_lib_functions.h"
#include "my_macro.h"
#include <unistd.h>

int print_error_message(char *str)
{
    write(2, str, my_strlen(str));
    return ERROR;
}

int is_empty_line(const char *line)
{
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
            return 0;
    }
    return 1;
}
