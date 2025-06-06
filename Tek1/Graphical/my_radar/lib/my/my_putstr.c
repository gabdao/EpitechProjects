/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** Display one by one the characters of a string
*/
#include <stdio.h>
#include <unistd.h>
#include "my_lib.h"
int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}
