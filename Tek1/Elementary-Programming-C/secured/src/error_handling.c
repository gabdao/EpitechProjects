/*
** EPITECH PROJECT, 2025
** hash_handling
** File description:
** File that regroups all the function to handle data in hash tables
*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/my.h"
#include "../include/my_macro.h"
#include "../include/my_secured.h"

int print_errors_messages(const char *message)
{
    if (!message) {
        return ERROR;
    }
    write(2, message, my_strlen(message));
    return ERROR;
}
