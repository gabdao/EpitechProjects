/*
** EPITECH PROJECT, 2025
** path_handling
** File description:
** file to handle path and command finding
*/

#include "my.h"
#include "my_mini_shell.h"
#include "my_macro.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

char *get_path_from_new_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "PATH=", 5) == SUCCESS) {
            return env[i] + 5;
        }
    }
    return NULL;
}

static char *check_name(char *each_path, struct dirent *entry, char *command)
{
    char *full_path = NULL;

    if (my_strcmp(entry->d_name, command) == SUCCESS) {
        full_path = malloc(my_strlen(each_path) + my_strlen(command) + 2);
        if (!full_path)
            return NULL;
        my_strcpy(full_path, each_path);
        my_strcat(full_path, "/");
        my_strcat(full_path, command);
        return full_path;
    }
    return NULL;
}

static char *search_command_in_dir(DIR *dir, char *each_path, char *command)
{
    struct dirent *entry = NULL;
    char *full_path = NULL;

    entry = readdir(dir);
    while (entry != NULL) {
        full_path = check_name(each_path, entry, command);
        if (full_path)
            return full_path;
        entry = readdir(dir);
    }
    return NULL;
}

static char *try_path(char *each_path, char *command)
{
    DIR *dir = opendir(each_path);
    char *full_path = NULL;

    if (!dir)
        return NULL;
    full_path = search_command_in_dir(dir, each_path, command);
    closedir(dir);
    return full_path;
}

char *find_command_in_path(char *path, char *command)
{
    char *path_copy = my_strdup(path);
    char *each_path = NULL;
    char *full_path = NULL;

    if (!path_copy)
        return NULL;
    each_path = strtok(path_copy, ":");
    while (each_path != NULL) {
        full_path = try_path(each_path, command);
        if (full_path) {
            free(path_copy);
            return full_path;
        }
        each_path = strtok(NULL, ":");
    }
    free(path_copy);
    return NULL;
}
