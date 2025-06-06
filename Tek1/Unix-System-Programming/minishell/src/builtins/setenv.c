/*
** EPITECH PROJECT, 2025
** setenv
** File description:
** file to handle setenv function
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

static char *build_var_string(char *name, char *value)
{
    int len = my_strlen(name) + 1;
    char *new_var = NULL;

    if (value != NULL)
        len += my_strlen(value);
    new_var = malloc(sizeof(char) * (len + 1));
    if (!new_var)
        return NULL;
    my_strcpy(new_var, name);
    my_strcat(new_var, "=");
    if (value != NULL)
        my_strcat(new_var, value);
    return new_var;
}

static int update_existing_var(char ***env, int index, char *new_var)
{
    free((*env)[index]);
    (*env)[index] = new_var;
    return SUCCESS;
}

static int add_new_var(char ***env, char *new_var)
{
    int len = get_env_length(*env);
    char **new_env = malloc(sizeof(char *) * (len + 2));
    int i = 0;

    if (!new_env)
        return ERROR;
    for (i = 0; i < len; i++) {
        new_env[i] = my_strdup((*env)[i]);
    }
    new_env[i] = new_var;
    new_env[i + 1] = NULL;
    my_free_array(*env);
    *env = new_env;
    return SUCCESS;
}

int handle_setenv(char **argv, char ***env, int argc)
{
    char *name = NULL;
    char *value = NULL;
    char *new_var = NULL;
    int index = 1;

    if (argc < 2 || argc > 3)
        return ERROR;
    name = argv[1];
    if (!is_valid_env_name(name)) {
        write(2, "setenv: Variable name must begin with a letter.\n", 47);
        return ERROR_NAME_ENV;
    }
    value = (argc == 3) ? argv[2] : NULL;
    new_var = build_var_string(name, value);
    if (!new_var)
        return ERROR;
    index = find_var_index(*env, name);
    if (index >= 0)
        return update_existing_var(env, index, new_var);
    return add_new_var(env, new_var);
}
