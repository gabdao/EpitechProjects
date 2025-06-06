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

static void handle_node(body_t *current, FILE *fd)
{
    while (current != NULL) {
        handle_opcode(current, fd);
        handle_params(current, fd);
        current = current->next;
    }
}

static void body_writing(body_t **body_list, FILE *fd)
{
    body_t *current = *body_list;

    handle_node(current, fd);
}

void body_writing_handling(body_t *body_list, FILE *fd)
{
    print_linked_list_body_data(body_list);
    body_writing(&body_list, fd);
}
