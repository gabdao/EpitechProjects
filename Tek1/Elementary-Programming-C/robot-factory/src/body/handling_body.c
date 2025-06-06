/*
** EPITECH PROJECT, 2025
** handling parsing in body
** File description:
** file to handle parsing body
*/

#include "my_lib_functions.h"
#include "op.h"
#include "robot_factory.h"
#include "my_macro.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

void handling_labels(char *label, body_t *body)
{
    mini_printf("label is: %s\n", label);
    body->label = my_strdup(label);
}

void handling_opcode(char *opcode, body_t *body)
{
    body->opcode = my_strdup(opcode);
}

void handling_parameters(char *parameter, body_t *body, int i)
{
    body->parameters[i] = my_strdup(parameter);
}

int handling_body(char **instruction, body_t **body_list)
{
    body_t *new_node = create_body_node();

    if (new_node == NULL)
        return ERROR;
    if (check_conditions_body(instruction, new_node) == ERROR) {
        free_body_list(new_node);
        return ERROR;
    }
    add_body_node(body_list, new_node);
    return SUCCESS;
}
