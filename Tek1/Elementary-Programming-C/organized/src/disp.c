/*
** EPITECH PROJECT, 2024
** Organized delete file
** File description:
** Handling delete function
*/

#include "my.h"
#include "shell.h"
#include "my_macro.h"
#include "materials.h"
#include <stdlib.h>
#include <stdio.h>

int disp(void *data, char **args)
{
    materials_t *workshop = *(materials_t **)data;

    while (workshop) {
        my_printf("%s n°%d - \"%s\"\n",
        workshop->category,
        workshop->id,
        workshop->name);
        workshop = workshop->next;
    }
    return 0;
}
