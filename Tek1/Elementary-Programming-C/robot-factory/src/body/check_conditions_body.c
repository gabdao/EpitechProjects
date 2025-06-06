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
#include <stdbool.h>

static bool check_label(char **instruction, body_t *body)
{
    int len_label = my_strlen(instruction[0]);

    if (instruction[0][len_label - 1] == LABEL_CHAR) {
        handling_labels(instruction[0], body);
        return true;
    }
    return false;
}

static int check_if_label_alone(char **instruction)
{
    int len_label = my_strlen(instruction[0]);

    if (instruction[0][len_label - 1] == ':' && instruction[1] == NULL) {
        return SUCCESS;
    }
    return ERROR;
}

static int check_opcode(char **instruction, bool is_label_found, body_t *body)
{
    char *opcode = is_label_found ? instruction[1] : instruction[0];

    if (check_if_label_alone(instruction) == SUCCESS) {
        return SUCCESS;
    }
    for (int i = 0; op_tab[i].mnemonique != NULL; i++) {
        if (my_strcmp(opcode, op_tab[i].mnemonique) == SUCCESS) {
            handling_opcode(opcode, body);
            return SUCCESS;
        }
    }
    mini_printf("----no correspond found for opcode----\n");
    return ERROR;
}

static int check_parameter(char **instruction,
    bool is_label_found, body_t *body)
{
    int i = 0;

    if (is_label_found == LABEL_FOUND)
        i = 2;
    if (is_label_found == LABEL_NOT_FOUND)
        i = 1;
    for (; instruction[i] != NULL; i++) {
        if (is_label_found == LABEL_FOUND && i == NB_ARGS_MAX_WITH_LABEL) {
            mini_printf("too much parameters with label found\n");
            return ERROR;
        }
        if (is_label_found == LABEL_NOT_FOUND && i == NB_ARGS_MAX) {
            mini_printf("too much parameters without label found\n");
            return ERROR;
        }
        handling_parameters(instruction[i], body, i);
    }
    return SUCCESS;
}

int check_conditions_body(char **instruction, body_t *body)
{
    bool is_label_found = check_label(instruction, body);

    if (check_opcode(instruction, is_label_found, body) == ERROR) {
        return ERROR;
    }
    if (check_parameter(instruction, is_label_found, body) == ERROR) {
        return ERROR;
    }
    return SUCCESS;
}
