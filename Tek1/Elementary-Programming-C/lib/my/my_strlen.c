/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** Returns the numbers of char in an str.
*/

#include "../../include/my.h"

int my_strlen(char const *str)
{
    int counter = 0;

    while (str[counter] != '\0') {
        counter++;
    }
    return counter;
}
