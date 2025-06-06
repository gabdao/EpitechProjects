/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** Counts and returns the number of characters found in a string
*/
#include <stdio.h>
#include <unistd.h>

int my_strlen(char const *str)
{
    int length;

    if (str == NULL) {
        return 0;
    }
    for (length = 0; str[length] != '\0'; length++);
    return length;
}
