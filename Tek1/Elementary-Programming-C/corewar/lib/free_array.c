/*
** EPITECH PROJECT, 2025
** cd
** File description:
** file to recreate cd function
*/

#include <stdlib.h>

int my_free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        array[i] = NULL;
        free(array[i]);
    }
    return 0;
}
