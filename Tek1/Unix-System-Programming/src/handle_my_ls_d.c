/*
** EPITECH PROJECT, 2024
** handle my_ls_d
** File description:
** Function to handle my_ls_d
*/

#include "../include/my.h"
#include <stdarg.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>


static int manage_directory_or_file(char *content)
{
    struct stat file_stat;

    if (stat(content, &file_stat) == -1) {
        my_printf("my_ls: cannot access '%s': ", content);
        perror("");
        return 1;
    }
    if (S_ISDIR(file_stat.st_mode) || S_ISREG(file_stat.st_mode)) {
        my_printf("%s  ", content);
    }
    return 0;
}

int handle_my_ls_d(int argc, char *argv[], char **content)
{
    if (argc == 2) {
        my_printf(".");
        return 0;
    }
    for (int i = 0; content[i] != NULL; i++) {
        manage_directory_or_file(content[i]);
    }
    return 0;
}
