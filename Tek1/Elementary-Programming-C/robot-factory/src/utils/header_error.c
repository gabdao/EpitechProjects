/*
** EPITECH PROJECT, 2025
** handling parser
** File description:
** file to handle parsing
*/

#include "my_lib_functions.h"
#include "op.h"
#include "robot_factory.h"
#include "my_macro.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

int check_name_errors(char **header_data)
{
    if (header_data[1] == NULL)
        return ERROR;
    if (my_strlen(header_data[1]) > PROG_NAME_LENGTH + 1)
        return ERROR;
    return SUCCESS;
}

int check_comment_errors(char **header_data)
{
    if (header_data[1] == NULL)
        return ERROR;
    if (my_strlen(header_data[1]) > COMMENT_LENGTH + 1)
        return ERROR;
    return SUCCESS;
}

int ignore_comment(char *line)
{
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '#') {
            mini_printf("comment found and ignored\n");
            return COMMENT_FOUND;
        }
    }
    return SUCCESS;
}
