/*
** EPITECH PROJECT, 2025
** hash_data
** File description:
** hash entry data to retrive index
*/
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/my.h"
#include "../include/my_secured.h"

int hash(char *key, int len)
{
    int sum = 0;

    for (int i = 0; key[i] != '\0'; i++) {
        sum += key[i];
    }
    return sum % len;
}
