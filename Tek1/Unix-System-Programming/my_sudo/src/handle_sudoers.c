/*
** EPITECH PROJECT, 2025
** main
** File description:
** main for sudo
*/

#include "my.h"
#include "my_macro.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static int loop(FILE *file, const char *username)
{
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, username)) {
            return SUCCESS;
        }
    }
    return ERROR;
}

int handle_sudoers(const char *username)
{
    FILE *file = fopen("/etc/sudoers", "r");
    int found;

    if (!file) {
        fprintf(stderr, "Error: Unable to open /etc/sudoers.\n");
        return ERROR;
    }
    found = loop(file, username);
    fclose(file);
    if (found == ERROR) {
        fprintf(stderr,
            "Error: User %s is not allowed to use sudo.\n", username);
        return ERROR;
    }
    return SUCCESS;
}
