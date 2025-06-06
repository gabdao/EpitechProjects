/*
** EPITECH PROJECT, 2024
** my_strncpy
** File description:
** Function that copies a string into another for n characters
*/
#include <stdio.h>
#include <unistd.h>
static int my_strlen(char const *str)
{
    int length;

    if (str == NULL) {
        return 0;
    }
    for (length = 0; str[length] != '\0'; length++);
    return length;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; i < n; i++) {
        dest[i] = src[i];
    }
    if (my_strlen(src) > n) {
        dest[i] = '\0';
    }
}
