/*
** EPITECH PROJECT, 2024
** my_isneg
** File description:
** Display either N if integer is negative or P if positive or null
*/
#include <stdio.h>
#include <unistd.h>
#include "../../include/my.h"
int my_isneg(int number)
{
    char positive;
    char negative;

    positive = 80;
    negative = 78;
    if (number >= 0) {
        my_putchar(80);
        my_putchar('\n');
    } else {
        my_putchar(negative);
        my_putchar('\n');
    }
}
