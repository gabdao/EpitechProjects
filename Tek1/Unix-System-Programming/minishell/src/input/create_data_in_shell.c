/*
** EPITECH PROJECT, 2025
** create_data_in_shell
** File description:
** file to handle data creation in shell
*/

#include "my.h"
#include "my_mini_shell.h"
#include "my_macro.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **read_stdin_and_convert_input_to_new_argv(char **new_argv)
{
    char *commands = NULL;
    size_t size = 0;

    if (getline(&commands, &size, stdin) == EOF) {
        return NULL;
    }
    if (commands[my_strlen(commands) - 1] == '\n') {
        commands[my_strlen(commands) - 1] = '\0';
    }
    if (commands[0] == '\0') {
        free(commands);
        return NULL;
    }
    new_argv = my_str_to_word_array_su(commands);
    free(commands);
    return new_argv;
}

int counting_new_argc(char **new_argv)
{
    int count = 0;

    for (int i = 0; new_argv[i] != NULL; i++) {
        count++;
    }
    return count;
}

char **copy_env_to_new_env(char **env, char **new_env)
{
    int len = 0;
    int i = 0;

    while (env[len] != NULL) {
        len++;
    }
    new_env = malloc((len + 1) * sizeof(char *));
    if (!new_env) {
        return NULL;
    }
    for (i = 0; i < len; i++) {
        new_env[i] = malloc(my_strlen(env[i]) + 1);
        my_strcpy(new_env[i], env[i]);
    }
    new_env[len] = NULL;
    return new_env;
}
