/*
** EPITECH PROJECT, 2025
** main
** File description:
** main for sudo
*/

#include "my.h"
#include "my_macro.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int my_exec(char **argv)
{
    if (!argv || !argv[0]) {
        fprintf(stderr, "Error: No command provided.\n");
        return ERROR;
    }
    execvp(argv[1], &argv[1]);
    fprintf(stderr, "Error: Command not found or execution failed.\n");
    return ERROR;
}
