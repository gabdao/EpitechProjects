/*
** EPITECH PROJECT, 2025
** handle several cmds
** File description:
** file to handle several cmds
*/

#include "my.h"
#include "my_mini_shell.h"
#include "my_macro.h"
#include <stdlib.h>

static int execute_command_cuted(char **argv, int start, int end, char ***env)
{
    char **array_cuted = NULL;
    int return_value = SUCCESS;

    array_cuted = strdup_array(argv, start, end);
    if (!array_cuted)
        return ERROR;
    return_value = check_new_argv(array_cuted, env,
        counting_new_argc(array_cuted));
    my_free_array(array_cuted);
    return return_value;
}

int handle_multiple_commands(char **argv, char ***env)
{
    int start = 0;
    int i = 0;
    int return_value = SUCCESS;

    while (argv[i]) {
        if (my_strcmp(argv[i], ";") == SUCCESS) {
            return_value = execute_command_cuted(argv, start, i, env);
            start = i + 1;
        }
        i++;
    }
    if (start < i) {
        return_value = execute_command_cuted(argv, start, i, env);
    }
    return return_value;
}
