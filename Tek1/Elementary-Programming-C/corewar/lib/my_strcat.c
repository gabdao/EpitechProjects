/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** my_strcat
*/

#include "my_lib_functions.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    for (; dest[j] != '\0'; j++);
    for (; src[i] != '\0'; i++) {
        dest[j] = src[i];
        j++;
    }
    dest[j] = '\0';
    return dest;
}
