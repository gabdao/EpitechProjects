/*
** EPITECH PROJECT, 2024
** my_revstr
** File description:
** Function that reverses a string
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

char *my_revstr(char *str)
{
    int i = 0;
    int n = my_strlen(str);
    char new_str[n + 1];

    for (; i < n; i++) {
        new_str[i] = str[n -1 - i];
    }
    new_str[i] = '\0';
}
