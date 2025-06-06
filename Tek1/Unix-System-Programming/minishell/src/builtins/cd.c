/*
** EPITECH PROJECT, 2025
** cd
** File description:
** file to recreate cd function
*/

#include "my.h"
#include "my_mini_shell.h"
#include "my_macro.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int change_directory(char *path, char **previous_directory)
{
    char *current_directory = getcwd(NULL, 0);

    if (!current_directory) {
        perror("getcwd failed");
        return ERROR;
    }
    if (chdir(path) == -1) {
        write(2, path, my_strlen(path));
        write(2, ": Not a directory.\n", 18);
        free(current_directory);
        return ERROR_DIR;
    }
    if (*previous_directory) {
        free(*previous_directory);
    }
    *previous_directory = current_directory;
    my_printf("changed\n");
    return SUCCESS;
}

static void home_directory(char **new_env, char **previous_directory)
{
    char *path_home_user = NULL;

    for (int i = 0; new_env[i] != NULL; i++) {
        if (my_strncmp(new_env[i], "HOME=", 5) == SUCCESS) {
            path_home_user = new_env[i] + 5;
            my_printf("path is %s\n", path_home_user);
            change_directory(path_home_user, previous_directory);
        }
    }
    my_printf("cd didnt find HOME \n");
}

static void handle_previous_directory(char **previous_directory)
{
    if (!*previous_directory) {
        my_printf("cd: OLDPWD not set\n");
        return;
    }
    change_directory(*previous_directory, previous_directory);
}

int handle_cd(char **new_argv, char ***new_env, int new_argc)
{
    static char *previous_directory = NULL;

    if (new_argc < 2) {
        home_directory(*new_env, &previous_directory);
        return SUCCESS;
    }
    if (my_strcmp(new_argv[1], "-") == SUCCESS) {
        handle_previous_directory(&previous_directory);
        return SUCCESS;
    }
    if (new_argv[1]) {
        if (change_directory(new_argv[1], &previous_directory) == ERROR_DIR) {
            return ERROR_DIR;
        }
        return SUCCESS;
    }
    return SUCCESS;
}
