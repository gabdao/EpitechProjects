/*
** EPITECH PROJECT, 2024
** B-PSU-100-PAR-1-1-mytop-raphael.varichon-dupre
** File description:
** get_file_size.c
*/

#include <sys/stat.h>
#include <stdio.h>

long int get_file_size(FILE *file)
{
    struct stat st;
    int fd = fileno(file);

    if (fstat(fd, &st) < 0) {
        return -1;
    }
    return st.st_size;
}
