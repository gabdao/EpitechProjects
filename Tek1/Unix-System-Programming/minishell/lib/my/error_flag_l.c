/*
** EPITECH PROJECT, 2024
** handle my_ls_l
** File description:
** Function to handle my_ls_l
*/

#include "../../include/my.h"
#include "../../include/my_macro.h"
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

int errors_in_stderr_l(int argc, const char *content)
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
