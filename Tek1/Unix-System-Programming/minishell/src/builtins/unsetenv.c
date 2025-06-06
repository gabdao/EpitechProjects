/*
** EPITECH PROJECT, 2025
** unsetenv
** File description:
** file to handle unsetenv function
*/

#include "my.h"
#include "my_mini_shell.h"
#include "my_macro.h"
#include <stdlib.h>
#include <string.h>

static int get_env_length(char **env)
{
    int len = 0;

    while (env[len] != NULL) {
        len++;
    }
    return len;
}

static int find_var_index(char **env, char *name)
{
    int i = 0;
    int name_len = my_strlen(name);

    for (i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], name, name_len) == SUCCESS
        && env[i][name_len] == '=')
            return i;
    }
    return -1;
}

static int remove_env_var(char ***env, int index)
{
    int len = get_env_length(*env);
    char **new_env = malloc(sizeof(char *) * len);
    int i = 0;
    int j = 0;

    if (!new_env)
        return ERROR;
    for (i = 0; i < len; i++) {
        if (i == index)
            continue;
        new_env[j] = my_strdup((*env)[i]);
        j++;
    }
    new_env[j] = NULL;
    my_free_array(*env);
    *env = new_env;
    return SUCCESS;
}

int handle_unsetenv(char **argv, char ***env, int argc)
{
    int index = -1;
    int i = 1;

    if (argc < 2)
        return ERROR;
    while (argv[i] != NULL) {
        index = find_var_index(*env, argv[i]);
        if (index >= 0)
            remove_env_var(env, index);
        i++;
    }
    return SUCCESS;
}
