/*
** EPITECH PROJECT, 2024
** handle my_ls_r
** File description:
** Function to handle my_ls_r
*/

#include "../../include/my.h"
#include <stdarg.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

static int open_read_directory_and_count(void)
{
    struct dirent *data_directory;
    DIR *dir = opendir(".");
    int count = 0;

    if (dir == NULL) {
        perror("Couldn't open directory");
        return -1;
    }
    data_directory = readdir(dir);
    while (data_directory != NULL) {
        if (data_directory->d_name[0] != '.') {
        count++;
        }
            data_directory = readdir(dir);
    }
    closedir(dir);
    return count;
}

char **create_table_for_files_names(int count)
{
    char **table_size = malloc(count * sizeof(char *));

    if (table_size == NULL) {
        perror("malloc failed");
        return NULL;
    }
    return table_size;
}

static int manage_error_in_table_check(char **table_size, int index, DIR *dir)
{
    if (table_size[index] == NULL) {
            perror("malloc failed");
            closedir(dir);
            return 1;
    }
    return 0;
}

char **store_file_names_in_table(char **table_size, int count)
{
    int index = 0;
    DIR *dir = opendir(".");
    struct dirent *data_directory;

    data_directory = readdir(dir);
    if (dir == NULL) {
        perror("Couldn't open directory");
        return NULL;
    }
    while (data_directory != NULL && index < count) {
        if (data_directory->d_name[0] != '.') {
            table_size[index] = malloc(my_strlen(data_directory->d_name) + 1);
            manage_error_in_table_check(table_size, index, dir);
            my_strcpy(table_size[index], data_directory->d_name);
            index++;
        }
        data_directory = readdir(dir);
    }
    closedir(dir);
    return table_size;
}

static int display_reverse_order(char **table_filled, int count)
{
    int i = 0;

    for (; i < count; i++) {
        my_printf("%s", table_filled[count - 1 - i]);
        my_printf("  ");
        free(table_filled[count - 1 - i]);
    }
    free(table_filled);
    return 0;
}

int handle_my_ls_r(int argc, char *argv[], char **content)
{
    int count;
    char **table_size;
    char **table_filled;

    count = open_read_directory_and_count();
    table_size = create_table_for_files_names(count);
    table_filled = store_file_names_in_table(table_size, count);
    display_reverse_order(table_filled, count);
    return 0;
}
