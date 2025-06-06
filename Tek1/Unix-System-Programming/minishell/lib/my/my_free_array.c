/*
** EPITECH PROJECT, 2025
** cd
** File description:
** file to recreate cd function
*/

#include <stdlib.h>

int my_free_array(char **array)
{
    if (!array)
        return 0;
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
    return 0;
}
