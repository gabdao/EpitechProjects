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

static int usage_tutorial(void)
{
    printf("usage: ./my_sudo -h\n");
    printf("usage: ./my_sudo [-ugEs] [command [args ...]]\n");
    return SUCCESS;
}

static int delete_ressources(env_info_t *info)
{
    free(info->user);
    free(info->shell);
    free(info->home);
    free(info);
    return SUCCESS;
}

static int check_args(int ac, char **av)
{
    if (ac == 1) {
        return ERROR;
    }
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        usage_tutorial();
        return TUTORIAL;
    }
    return SUCCESS;
}

int main(int ac, char **av, char **env)
{
    env_info_t *info = get_env_info(env);
    int check_result = check_args(ac, av);

    if (check_result == ERROR) {
        fprintf(stderr, "Error: Need args.\n");
        return ERROR;
    }
    if (check_result == TUTORIAL) {
        return SUCCESS;
    }
    if (!info) {
        fprintf(stderr, "Error: Failed to retrieve environment variables.\n");
        return ERROR;
    }
    if (handle_sudoers(info->user) == SUCCESS &&
        handling_password_auth(info->user) == SUCCESS) {
        my_exec(av);
    }
    delete_ressources(info);
    return SUCCESS;
}
