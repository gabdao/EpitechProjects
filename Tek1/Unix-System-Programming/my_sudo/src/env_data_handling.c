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

static int error_handling_in_env(char **env, env_info_t *info)
{
    if (!info->user) {
        fprintf(stderr, "Error: Missing User environment variables.\n");
        free(info);
        return ERROR;
    }
    if (!info->shell) {
        fprintf(stderr, "Error: Missing Shell environment variables.\n");
        free(info);
        return ERROR;
    }
    if (!info->home) {
        fprintf(stderr, "Error: Missing Home environment variables.\n");
        free(info);
        return ERROR;
    }
    return SUCCESS;
}

static int searching_in_env(char **env, env_info_t *info)
{
    int i = 0;

    for (; env[i] != NULL; i++) {
        if (strncmp(env[i], "USER=", 5) == 0) {
            info->user = strdup(env[i] + 5);
        }
        if (strncmp(env[i], "SHELL=", 6) == 0) {
            info->shell = strdup(env[i] + 6);
        }
        if (strncmp(env[i], "HOME=", 5) == 0) {
            info->home = strdup(env[i] + 5);
        }
    }
    return SUCCESS;
}

env_info_t *get_env_info(char **env)
{
    env_info_t *info = malloc(sizeof(env_info_t));

    if (!info) {
        return NULL;
    }
    info->user = NULL;
    info->shell = NULL;
    info->home = NULL;
    searching_in_env(env, info);
    error_handling_in_env(env, info);
    return info;
}
