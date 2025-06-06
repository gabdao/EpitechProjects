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

const struct builtins_and_functions builtins[] = {
    {"cd", handle_cd},
    {"setenv", handle_setenv},
    {"unsetenv", handle_unsetenv},
    {"env", handle_env},
    {"exit", handle_exit},
    {NULL, NULL}
};

static int check_builtin_return(int value)
{
    for (int i = 0; RETURN_VALUES[i].message != NULL; i++) {
        if (value == RETURN_VALUES[i].code) {
            return value;
        }
    }
    return ERROR;
}

static int check_ptr_function(
    char **new_argv,
    char ***new_env,
    int new_argc,
    int i)
{
    int return_value;

    if (my_strcmp(new_argv[0], builtins[i].builtins) == SUCCESS) {
        return_value = builtins[i].function_ptr(new_argv, new_env, new_argc);
        return check_builtin_return(return_value);
    }
    return NOT_A_BUILTIN;
}

int check_new_argv(char **new_argv, char ***new_env, int new_argc)
{
    int return_value = 0;

    for (int i = 0; builtins[i].builtins != NULL; i++) {
        return_value = check_ptr_function(new_argv, new_env, new_argc, i);
        if (return_value != NOT_A_BUILTIN) {
            return return_value;
        }
    }
    return handle_extern_commands(new_argv, *new_env);
}
