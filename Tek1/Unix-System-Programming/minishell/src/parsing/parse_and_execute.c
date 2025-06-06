/*
** EPITECH PROJECT, 2025
** handle new argv
** File description:
** file to handle new argv
*/

#include "my.h"
#include "my_mini_shell.h"
#include "my_macro.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int parse_and_execute(char **argv, char ***env, separator_flags_t flags)
{
    if (flags.separator > 0)
        return handle_multiple_commands(argv, env);
    if (flags.pipe > 0)
        return handle_pipe_command(argv, env);
    if (flags.redirection > 0)
        return handle_redirection(argv, env);
    return ERROR;
}
