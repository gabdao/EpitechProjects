/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** function that allocates memory and copies the string
*/

#include <stdlib.h>
#include "my_lib_functions.h"

char *my_strdup(char const *src)
{
    char *str = NULL;
    int i = 0;

    str = malloc(sizeof(char) * (my_strlen(src)) + 1);
    for (i = 0; i < my_strlen(src); i++) {
        str[i] = src[i];
    }
    str[i] = '\0';
    return str;
}
