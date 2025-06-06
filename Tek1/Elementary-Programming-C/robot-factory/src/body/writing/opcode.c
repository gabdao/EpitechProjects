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

static const opcode_t opcode_table[] = {
    {"live", 0x01}, {"ld", 0x02}, {"st", 0x03}, {"add", 0x04},
    {"sub", 0x05}, {"and", 0x06}, {"or", 0x07}, {"xor", 0x08},
    {"zjmp", 0x09}, {"ldi", 0x0A}, {"sti", 0x0B}, {"fork", 0x0C},
    {"lld", 0x0D}, {"lldi", 0x0E}, {"lfork", 0x0F}, {"aff", 0x10},
    {NULL, 0x00}
};

static void writing_opcode(uint8_t opcode, FILE *fd)
{
    fwrite(&opcode, sizeof(uint8_t), 1, fd);
}

static uint8_t get_opcode_value(char *opcode)
{
    if (opcode == NULL)
        return 0;
    for (size_t i = 0; opcode_table[i].opcode != NULL; i++) {
        if (my_strcmp(opcode, opcode_table[i].opcode) == SUCCESS) {
            return opcode_table[i].value;
        }
    }
    return SUCCESS;
}

void handle_opcode(body_t *body_list, FILE *fd)
{
    uint8_t opcode = get_opcode_value(body_list->opcode);

    writing_opcode(opcode, fd);
}
