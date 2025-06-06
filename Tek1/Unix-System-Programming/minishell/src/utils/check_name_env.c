/*
** EPITECH PROJECT, 2025
** setenv check name
** File description:
** file to check new env var name
*/

#include "my.h"
#include "my_mini_shell.h"
#include "my_macro.h"
#include <stdlib.h>
#include <string.h>

int is_valid_env_name(char *name)
{
    int i = 0;

    if (name == NULL)
        return 0;
    if (!((name[0] >= 'A' && name[0] <= 'Z')
        || (name[0] >= 'a' && name[0] <= 'z')
        || name[0] == '_'))
        return 0;
    for (i = 1; name[i] != '\0'; i++) {
        if (!((name[i] >= 'A' && name[i] <= 'Z')
        || (name[i] >= 'a' && name[i] <= 'z')
        || (name[i] >= '0' && name[i] <= '9')
        || name[i] == '_'))
        return 0;
    }
    return 1;
}
