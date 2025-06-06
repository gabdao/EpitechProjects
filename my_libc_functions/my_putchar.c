/*
** EPITECH PROJECT, 2024
** my_putchar
** File description:
** Display characters
*/
#include <stdio.h>

int my_putchar(char c)
{
    write(1, &c, 1);
}
