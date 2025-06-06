/*
** EPITECH PROJECT, 2024
** handle my_ls_no_flags
** File description:
** Function to handle my_ls with no flags only arguments
*/

#include "../../include/my.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include "../../include/my_macro.h"
#include <stdlib.h>

static int print_file_name(const char *file_name)
{
    my_printf("%s\n", file_name);
    return 0;
}

static int handle_directory_content(const char *dir_name)
{
    struct dirent *data_directory;
    DIR *dir = opendir(dir_name);

    if (dir == NULL) {
        perror("Couldn't open directory");
        return 0;
    }
    data_directory = readdir(dir);
    while (data_directory != NULL) {
        if (data_directory->d_name[0] != '.') {
            my_printf("%s  ", data_directory->d_name);
        }
        data_directory = readdir(dir);
    }
    my_printf("\n");
    closedir(dir);
    return 0;
}

static int check_type_of_file(struct stat *file_stat, char **content, int i)
{
    if (S_ISDIR(file_stat->st_mode)) {
            handle_directory_content(content[i]);
        } else if (S_ISREG(file_stat->st_mode)) {
            print_file_name(content[i]);
        }
    return 0;
}

static int errors_in_stderr(int argc, const char *content)
{
    char *error_message;

        error_message = malloc(sizeof(int) * (SIZE_P + my_strlen(content)));
        my_strcat(error_message, "ls: cannot access '");
        my_strcat(error_message, content);
        my_strcat(error_message, "'");
        perror(error_message);
        exit(EXIT_FAILURE);
    return 84;
}

int handle_my_ls_no_flags(int argc, char *argv[], char **content)
{
    struct stat file_stat;

    for (int i = 0; content[i] != NULL; i++) {
        if (stat(content[i], &file_stat) == -1) {
            errors_in_stderr(argc, content[i]);
            continue;
        }
        check_type_of_file(&file_stat, content, i);
    }
    return 0;
}
