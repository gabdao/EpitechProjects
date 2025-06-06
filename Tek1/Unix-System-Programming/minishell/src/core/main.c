/*
** EPITECH PROJECT, 2025
** main
** File description:
** main for mini shell 1
*/

#include "my.h"
#include "my_mini_shell.h"
#include "my_macro.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv, char **env)
{
    int return_value = shell_loop(env);

    for (int i = 0; RETURN_VALUES[i].code != -1; i++) {
        if (return_value == RETURN_VALUES[i].code) {
            return RETURN_VALUES[i].code;
        }
    }
    return ERROR;
}
