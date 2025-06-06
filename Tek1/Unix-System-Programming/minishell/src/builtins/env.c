/*
** EPITECH PROJECT, 2025
** env
** File description:
** file to handle env function
*/

#include "my.h"
#include "my_mini_shell.h"
#include "my_macro.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int handle_env(char **new_argv, char ***new_env, int new_argc)
{
    for (int i = 0; (*new_env)[i] != NULL; i++) {
        my_printf("%s\n", (*new_env)[i]);
    }
    return SUCCESS;
}
