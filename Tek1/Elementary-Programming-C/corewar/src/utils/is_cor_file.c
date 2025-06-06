/*
** EPITECH PROJECT, 2025
** reader
** File description:
** reading args and parsing
*/

#include <stdbool.h>
#include "my_lib_functions.h"

bool is_dot_cor_file(const char *filename)
{
    int len = my_strlen(filename);

    return (len >= 4 && my_strcmp(&filename[len - 4], ".cor") == 0);
}
