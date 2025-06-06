/*
** EPITECH PROJECT, 2025
** shell_loop
** File description:
** shell loop and command handling functions
*/

#include "my.h"
#include "my_mini_shell.h"
#include "my_macro.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int display_prompt(void)
{
    if (isatty(SUCCESS))
        write(1, "$> ", 3);
    return SUCCESS;
}

static int execute_command(char **new_argv, char ***new_env)
{
    int new_argc = counting_new_argc(new_argv);
    int return_value = dispatch_command(new_argv, new_env, new_argc);

    my_free_array(new_argv);
    return return_value;
}

static void handle_command(char **new_argv, char ***new_env, int *result)
{
    if (new_argv == NULL) {
        if (!isatty(0)) {
            *result = SUCCESS;
            return;
        }
        *result = SUCCESS;
        return;
    }
    *result = execute_command(new_argv, new_env);
}

static int handle_shell_exit(char **new_env, int status)
{
    my_free_array(new_env);
    return status;
}

int shell_loop(char **env)
{
    char **new_argv = NULL;
    char **new_env = NULL;
    int result = 0;

    new_env = copy_env_to_new_env(env, new_env);
    if (!new_env)
        return ERROR;
    while (SHELL) {
        display_prompt();
        new_argv = read_stdin_and_convert_input_to_new_argv(new_argv);
        handle_command(new_argv, &new_env, &result);
        if (result == EXIT || (!isatty(0) && new_argv == NULL))
            return handle_shell_exit(new_env, result);
        if (result != SUCCESS)
            return handle_shell_exit(new_env, result);
    }
    return handle_shell_exit(new_env, SUCCESS);
}
