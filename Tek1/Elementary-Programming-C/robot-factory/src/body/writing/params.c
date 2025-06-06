/*
** EPITECH PROJECT, 2025
** body writing
** File description:
** file to handle body writing
*/

#include "my_lib_functions.h"
#include "robot_factory.h"
#include "my_macro.h"
#include "op.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

static void writing_params(FILE *fd)
{
    mini_printf("test\n");
}

void handle_params(body_t *current, FILE *fd)
{
    for (int i = 0; i < 4; i++) {
        if (current->parameters[i] == NULL)
            continue;
        mini_printf("d :%s\n", current->parameters[i]);
    }
    writing_params(fd);
}
