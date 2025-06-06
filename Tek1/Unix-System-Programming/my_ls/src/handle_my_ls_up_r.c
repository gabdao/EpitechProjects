/*
** EPITECH PROJECT, 2024
** handle my_ls_R
** File description:
** Function to handle my_ls_R
*/

#include "../include/my.h"
#include <stdarg.h>
#include <stdio.h>

static int print_error(char *str_error)
{
    int len_error = my_strlen(str_error);

    write(2, str_error, len_error);
    return 84;
}

static int check_stat(const char *path, struct stat *file_stat)
{
    if (stat(path, file_stat) == -1) {
        perror("stat failed");
        return 1;
    }
    return 0;
}

static int path(char *filepath,
    char *data, struct stat *stat, struct dirent *doss)
{
    filepath[0] = '\0';
        my_strcat(filepath, data);
        if (filepath[my_strlen(filepath) - 1] != '/') {
            my_strcat(filepath, "/");
        }
        my_strcat(filepath, doss->d_name);
        if (check_stat(filepath, stat)) {
            return 1;
        }
    return 0;
}

static int process_entry(const char *dir_name, struct dirent *entry)
{
    struct stat file_stat;
    char filepath[1024];

    if (entry->d_name[0] == '.')
        return 0;
    if (path(filepath, (char *)dir_name, &file_stat, entry))
        return 1;
    if (S_ISDIR(file_stat.st_mode)) {
        my_printf("\n%s:\n", filepath);
        list_directory_content(filepath);
    }
    my_printf("%s\n", entry->d_name);
    return 0;
}

int list_directory_content(const char *dir_name)
{
    DIR *dir = opendir(dir_name);
    struct dirent *entry;

    if (dir == NULL) {
        perror("Couldn't open directory");
        return 1;
    }
    entry = readdir(dir);
    while (entry != NULL) {
        process_entry(dir_name, entry);
        entry = readdir(dir);
    }
    closedir(dir);
    return 0;
}

int handle_my_ls_up_r(int argc, char *argv[], char **content)
{
    for (int i = 0; content[i] != NULL; i++) {
        my_printf("%s:\n", content[i]);
        list_directory_content(content[i]);
    }
    return 0;
}
