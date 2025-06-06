/*
** EPITECH PROJECT, 2024
** my_putchar
** File description:
** my_putchar
*/

#include <unistd.h>
#include "my_lib_functions.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
