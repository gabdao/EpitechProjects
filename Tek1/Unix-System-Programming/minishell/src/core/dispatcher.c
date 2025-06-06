/*
** EPITECH PROJECT, 2025
** dispatcher
** File description:
** sorting by default command or special commands
*/

#include "my.h"
#include "my_mini_shell.h"
#include "my_macro.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static separator_flags_t detect_separators(char **argv)
{
    separator_flags_t flags = {0, 0, 0, 0};

    for (int i = 0; argv[i]; i++) {
        if (my_strcmp(argv[i], ";") == SUCCESS) {
            flags.separator++;
            flags.special_command++;
        }
        if (my_strcmp(argv[i], ">") == SUCCESS
        || my_strcmp(argv[i], "<") == SUCCESS) {
            flags.redirection++;
            flags.special_command++;
        }
    }
    return flags;
}

int dispatch_command(char **new_argv, char ***new_env, int new_argc)
{
    separator_flags_t flags = detect_separators(new_argv);

    if (flags.special_command > 0) {
        return parse_and_execute(new_argv, new_env, flags);
    }
    return check_new_argv(new_argv, new_env, new_argc);
}
