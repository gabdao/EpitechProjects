/*
** EPITECH PROJECT, 2024
** setting_up
** File description:
** Projet setting_up
*/
#include "my.h"
#include "my_macro.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

char *allocate_buffer(const char *filename, struct stat *st)
{
    char *buffer;
    int file_size;

    if (stat(filename, st) == -1) {
        print_errors_messages("Error getting file size\n");
        return NULL;
    }
    file_size = st->st_size;
    buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        print_errors_messages("Memory allocation failed\n");
        return NULL;
    }
    return buffer;
}

char *read_old_map_from_file(int fd, char *buffer, int file_size)
{
    ssize_t read_file;

    read_file = read(fd, buffer, file_size);
    if (read_file == -1) {
        print_errors_messages("Error reading file\n");
        free(buffer);
        close(fd);
        return NULL;
    }
    if (read_file == 0) {
        print_errors_messages("File is empty\n");
        free(buffer);
        close(fd);
        return NULL;
    }
    buffer[read_file] = '\0';
    close(fd);
    return buffer;
}

char *open_old_map_from_file(char *filename)
{
    struct stat st;
    int fd;
    char *buffer;
    int file_size;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        print_errors_messages("Error opening file\n");
        return NULL;
    }
    buffer = allocate_buffer(filename, &st);
    if (buffer == NULL) {
        print_errors_messages("Memory allocation failed\n");
        close(fd);
        return NULL;
    }
    file_size = st.st_size;
    return read_old_map_from_file(fd, buffer, file_size);
}

static int launch_and_end_algo(char *old_map, char **new_map)
{
    new_map = my_str_to_word_array_su(old_map);
    if (new_map == NULL) {
        free(old_map);
        return print_errors_messages("Error converting map to array\n");
    }
    launching_algo(new_map);
    free(new_map);
    free(old_map);
    return SUCCESS;
}

int main(int argc, char **argv)
{
    char *old_map;
    char **new_map;

    if (argc != 2) {
        return print_errors_messages("Arguments different from 2\n");
    }
    old_map = open_old_map_from_file(argv[1]);
    if (old_map == NULL) {
        return ERROR;
    }
    if (errors_handler(old_map) == ERROR) {
        free(old_map);
        return ERROR;
    }
    launch_and_end_algo(old_map, new_map);
    return SUCCESS;
}
