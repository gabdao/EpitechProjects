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

body_t *create_body_node(void)
{
    body_t *new_node = malloc(sizeof(body_t));

    if (new_node == NULL)
        return NULL;
    new_node->label = NULL;
    new_node->opcode = NULL;
    for (int i = 0; i < 4; i++) {
        new_node->parameters[i] = NULL;
    }
    new_node->next = NULL;
    return new_node;
}

void add_body_node(body_t **head, body_t *new_node)
{
    body_t *current = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }
    current = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = new_node;
}

void free_parameters_in_body_list(body_t *current)
{
    for (int i = 0; i < 4; i++) {
        if (current->parameters[i])
            free(current->parameters[i]);
    }
}

void free_body_list(body_t *head)
{
    body_t *current = head;
    body_t *next;

    while (current != NULL) {
        next = current->next;
        if (current->label)
            free(current->label);
        if (current->opcode)
            free(current->opcode);
        free_parameters_in_body_list(current);
        free(current);
        current = next;
    }
}
