/*
** EPITECH PROJECT, 2024
** handle my_ls_a
** File description:
** Function to handle my_ls_a
*/

#include "../../include/my.h"
#include <stdarg.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

static int manage_directory(DIR *dir, char **content, int i)
{
    struct dirent *data_directory;

    dir = opendir(content[i]);
    if (dir == NULL) {
        perror("Couldn't open directory");
    }
    data_directory = readdir(dir);
    while (data_directory != NULL) {
        my_printf("%s  ", data_directory->d_name);
        data_directory = readdir(dir);
    }
    closedir(dir);
    return 0;
}

static int manage_files(int i, char **content)
{
    my_printf(content[i]);
    return 0;
}

static int manage_errors_content(char **content, struct stat *file_stat, int i)
{
    if (stat(content[i], file_stat) == -1) {
            my_printf("my_ls: cannot access '%s': ", content[i]);
            perror("");
        }
    return 0;
}

int handle_my_ls_a(int argc, char *argv[], char **content)
{
    struct stat file_stat;
    DIR *dir;

    for (int i = 0; content[i] != NULL; i++) {
        manage_errors_content(content, &file_stat, i);
        if (S_ISDIR(file_stat.st_mode)) {
            manage_directory(dir, content, i);
        }
        if (S_ISREG(file_stat.st_mode)) {
            manage_files(i, content);
        }
    }
    return 0;
}
