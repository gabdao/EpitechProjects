/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-robotfactory-raphael.varichon-dupre
** File description:
** champion_file_size
*/

#include "robot_factory.h"
#include "op.h"
#include "my_lib_functions.h"
#include <stdio.h>
#include <stdbool.h>

static int handler_size_opcode(body_t **body)
{
    body_t *current = *body;
    int size_opcode = 0;

    while (current != NULL) {
        if (my_strcmp(current->opcode, "live") == 0
            || my_strcmp(current->opcode, "zjmp") == 0
            || my_strcmp(current->opcode, "fork") == 0
            || my_strcmp(current->opcode, "lfork") == 0)
            size_opcode += 1;
        else
            size_opcode += 2;
        current = current->next;
    }
    return size_opcode;
}

static int is_register(char **parameters)
{
    int count = 0;
    int count_register;

    for (int i = 1; i < 4; i++) {
        if (parameters[i][0] == 'r' && (parameters[i][1] >= '1'
            && parameters[i][1] <= REG_NUMBER + '0'))
                count++;
    }
    if (count == 3)
        count_register = 3;
    if (count == 2)
        count_register = 4;
    if (count == 1)
        count_register = 5;
    return count_register;
}

static int handler_size_index_parameters(body_t **body)
{
    body_t *current = *body;
    int size_indexes = 0;

    while (current != NULL) {
        if (my_strcmp(current->opcode, "zjmp") == 0)
            size_indexes += 2;
        if (my_strcmp(current->opcode, "ldi") == 0)
            size_indexes += is_register(current->parameters);
        if (my_strcmp(current->opcode, "sti") == 0)
            size_indexes += is_register(current->parameters);
        if (my_strcmp(current->opcode, "fork") == 0)
            size_indexes += 2;
        if (my_strcmp(current->opcode, "lldi") == 0)
            size_indexes += is_register(current->parameters);
        current = current->next;
    }
    return size_indexes;
}

static bool skip_indexes_instructions(char *opcode)
{
    char *index_opcode[] = {"zjmp", "ldi", "sti", "fork", "lldi", NULL};

    for (int i = 0; index_opcode[i] != NULL; i++) {
        if (my_strcmp(opcode, index_opcode[i]) == 0)
            return true;
    }
    return false;
}

static int get_size_parameter(char *parameters)
{
    if (parameters[0] == 'r' && (parameters[1] >= '1'
        && parameters[1] <= REG_NUMBER + '0'))
        return 1;
    else if (parameters[0] == DIRECT_CHAR)
        return DIR_SIZE;
    return IND_SIZE;
}

static void check_parameters(body_t *current, int *size_parameter)
{
    for (int i = 0; i < 4; i++) {
        if (current->parameters[i] == NULL)
            continue;
        if (skip_indexes_instructions(current->opcode))
            return;
        *size_parameter += get_size_parameter(current->parameters[i]);
    }
}

static int handler_size_parameters(body_t **body)
{
    body_t *current = *body;
    int size_parameters = 0;

    handler_size_index_parameters(body);
    while (current != NULL) {
        check_parameters(current, &size_parameters);
        current = current->next;
    }
    return size_parameters;
}

int get_prog_size(body_t **body)
{
    int prog_size = 0;

    prog_size =
                handler_size_opcode(body)
                + handler_size_index_parameters(body)
                + handler_size_parameters(body);
    return prog_size;
}
