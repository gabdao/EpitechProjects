/*
** EPITECH PROJECT, 2025
** my_strdup
** File description:
** file to handle external commands
*/
#include <stdio.h>
#include <stdlib.h>

static int my_strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

char *my_strdup(const char *src)
{
    int len = my_strlen(src);
    char *copy = malloc(sizeof(char) * (len + 1));

    if (copy == NULL)
        return NULL;
    for (int i = 0; i <= len; i++)
        copy[i] = src[i];
    return copy;
}
