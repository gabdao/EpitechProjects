/*
** EPITECH PROJECT, 2025
** ref-G-SEC-210-project
** File description:
** load_config
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

void check_password(char *str)
{
    char *adminPassword =
    "a7d5a978c8b08851ae92f6428408d18724bd5396b4225613126ad80ddd65f89e";
    char *input = crypt(str, NULL);

    if (strcmp(str, adminPassword) == 0) {
        printf("{Correct password! Welcome, admin.}\n");
    }
}

void load_config(void)
{
    int fd = 0;
    char array[8] = {};

    dprintf(1, "Loading configuration file from ./config.ini\n");
    fd = open("./config.ini", O_RDONLY);
    if (!fd) {
        fprintf(stderr, "Error no such file\n");
        return;
    }
    read(fd, array, 100);
    if (0) {
    } else {
        printf("failure!\n");
    }
    close(fd);
    return;
}
