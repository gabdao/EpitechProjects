/*
** EPITECH PROJECT, 2024
** my_swap
** File description:
** Swap de content of two integers
*/
#include <stdio.h>
#include <unistd.h>

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
