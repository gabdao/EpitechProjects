/*
** EPITECH PROJECT, 2024
** my_strstr
** File description:
** Function that returns the first occurence in 2 string
*/
#include <stddef.h>
#include "../../include/my.h"

int research(char *str, char const *to_find, int i)
{
    for (int j = 0; to_find[j] != '\0'; j++) {
        if (str[i + j] != to_find[j]) {
            return 0;
        }
    }
    return 1;
}

char *my_strstr(char *str, char const *to_find)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (research(str, to_find, i)) {
            return &str[i];
        }
    }
    return NULL;
}
