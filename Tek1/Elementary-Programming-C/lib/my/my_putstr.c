/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** Displays the chars of a string one by one
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (*(str + i) != '\0') {
        my_putchar(*(str + i));
        i++;
    }
    return (0);
}
