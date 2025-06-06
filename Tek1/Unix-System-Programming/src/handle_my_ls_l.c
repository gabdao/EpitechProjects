/*
** EPITECH PROJECT, 2024
** handle my_ls_l
** File description:
** Function to handle my_ls_l
*/

#include "../include/my.h"
#include "../include/my_macro.h"
#include <stdarg.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>

static int print_file_info(struct stat *file_stat, const char *filename)
{
    print_rights(file_stat->st_mode);
    my_printf(" ");
    print_owners(file_stat->st_uid, file_stat->st_gid, file_stat->st_nlink);
    my_printf(" ");
    print_data_size(file_stat->st_size);
    my_printf(" ");
    print_last_modification_date(file_stat->st_mtime);
    my_printf(" ");
    print_files_names(filename);
    return 0;
}

static int manage_errors_in_handle_directory_data(DIR *dir)
{
    if (dir == NULL) {
        perror("Couldn't open directory");
        return 1;
    }
    return 0;
}

static int check_stat(const char *path, struct stat *file_stat)
{
    if (stat(path, file_stat) == -1) {
        perror("stat failed");
        return 1;
    }
    return 0;
}

int path(char *filepath, char *data, struct stat *stat, struct dirent *doss)
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

static int handle_directory(char *content)
{
    struct dirent *doss;
    DIR *dir = opendir(content);
    struct stat file_stat;
    char filepath[PATH_MAX];

    manage_errors_in_handle_directory_data(dir);
    doss = readdir(dir);
    while (doss != NULL) {
        if (doss->d_name[0] == '.') {
            doss = readdir(dir);
            continue;
        }
        path(filepath, content, &file_stat, doss);
        print_file_info(&file_stat, doss->d_name);
        doss = readdir(dir);
    }
    closedir(dir);
    return 0;
}

static int check_type_of_file(struct stat *file_stat, char *content)
{
    if (S_ISDIR(file_stat->st_mode)) {
        handle_directory(content);
        } else if (S_ISREG(file_stat->st_mode)) {
            print_file_info(file_stat, content);
        }
    return 0;
}

static int handle_directory_data_without_args(void)
{
    struct dirent *data_directory;
    DIR *dir = opendir(".");
    struct stat file_stat;

    manage_errors_in_handle_directory_data(dir);
    data_directory = readdir(dir);
    while (data_directory != NULL) {
        if (data_directory->d_name[0] == '.') {
            data_directory = readdir(dir);
            continue;
        }
        if (check_stat(data_directory->d_name, &file_stat)) {
            closedir(dir);
            return 1;
        }
        print_file_info(&file_stat, data_directory->d_name);
        data_directory = readdir(dir);
    }
    closedir(dir);
    return 0;
}

int handle_my_ls_l(int argc, char *argv[], char **content)
{
    struct stat file_stat;

    if (argc == 2) {
        handle_directory_data_without_args();
        return 0;
    }
        for (int i = 0; content[i] != NULL; i++) {
            if (stat(content[i], &file_stat) == -1) {
                errors_in_stderr_l(argc, content[i]);
                continue;
            }
            check_type_of_file(&file_stat, content[i]);
        }
    return 0;
}
