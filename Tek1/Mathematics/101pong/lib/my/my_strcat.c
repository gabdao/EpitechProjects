/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** Function that
*/
#include <stddef.h>
#include "../../include/my.h"
char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    int n = my_strlen(dest);

    for (; i < n; i++) {
    }
    for (; src[j] != '\0'; i++) {
        dest[i] = src[j];
        j++;
    }
    dest[i] = '\0';
    return dest;
}
