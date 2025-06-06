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
#include <arpa/inet.h>

void print_parameters(body_t *current)
{
    for (int i = 0; i < 4; i++) {
        if (current->parameters[i] != NULL) {
            mini_printf("Paramètre %d: %s\n", i, current->parameters[i]);
        }
    }
}

void print_linked_list_body_data(body_t *body_list)
{
    body_t *current = body_list;

    mini_printf("\n----- BODY INFORMATION -----\n");
    while (current != NULL) {
        mini_printf("Label: %s\n", current->label ? current->label : "None");
        mini_printf("Opcode:%s\n", current->opcode ? current->opcode : "None");
        print_parameters(current);
        mini_printf("--------------------------\n");
        current = current->next;
    }
}
