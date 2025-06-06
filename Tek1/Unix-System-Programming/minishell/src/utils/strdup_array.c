/*
** EPITECH PROJECT, 2025
** handle several cmds
** File description:
** file to handle several cmds
*/

#include "my.h"
#include "my_mini_shell.h"
#include "my_macro.h"
#include <stdlib.h>

char **strdup_array(char **argv, int start, int end)
{
    int size = end - start;
    char **array_cuted = NULL;
    int i = 0;

    array_cuted = malloc(sizeof(char *) * (size + 1));
    if (!array_cuted)
        return NULL;
    for (i = 0; i < size; i++) {
        array_cuted[i] = my_strdup(argv[start + i]);
        if (!array_cuted[i]) {
            my_free_array(array_cuted);
            return NULL;
        }
    }
    array_cuted[i] = NULL;
    return array_cuted;
}
