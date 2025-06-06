/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** function that imitates strdup
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_strdup(const char *str)
{
    int len = 0;
    char *dup;

    len = my_strlen(str);
    dup = malloc(sizeof(char) * (len + 1));
    if (!dup) {
        return NULL;
    }
    for (int i = 0; i < len; i++) {
        dup[i] = str[i];
    }
    dup[len] = '\0';
    return dup;
}
