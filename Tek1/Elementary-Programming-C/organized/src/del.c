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

int args_error_handling(char **args)
{
    if (!args || !args[0]) {
        my_printf("Invalid command: no ID provided\n");
        return 84;
    }
    return 0;
}

static void delete_virgule(char *str)
{
    int len = my_strlen(str);

    if (len > 0 && str[len - 1] == ',') {
        str[len - 1] = '\0';
    }
}

int manage_id_format(int id_to_delete, char **args)
{
    if (id_to_delete < 0) {
        my_printf("Invalid ID: %s\n", args[0]);
        return 84;
    }
    return 0;
}

int replace_head_or_next(
    workshop_t *workshop,
    materials_t *current,
    materials_t *previous
)
{
    if (previous == NULL) {
        workshop->head = current->next;
    } else {
        previous->next = current->next;
    }
    return 0;
}

int loop_to_find_correct_id(workshop_t *workshop, int id_to_delete)
{
    materials_t *current = workshop->head;
    materials_t *previous = NULL;

    while (current) {
        if (current->id == id_to_delete) {
            replace_head_or_next(workshop, current, previous);
            my_printf("%s n°%d - \"%s\" deleted.\n",
            current->category,
            current->id,
            current->name);
            free(current->category);
            free(current->name);
            free(current);
            return 0;
        }
        previous = current;
        current = current->next;
    }
    return 84;
}

int del(void *data, char **args)
{
    workshop_t *workshop = (workshop_t *)data;
    int id_to_delete;
    int value_to_check_if_it_worked = SUCCESS;

    if (args_error_handling(args) == 84)
        return 84;
    for (int i = 0; args[i] != NULL; i++) {
        delete_virgule(args[i]);
        id_to_delete = my_atoi(args[i]);
        if (id_to_delete < 0) {
            my_printf("Invalid ID: %s\n", args[i]);
            value_to_check_if_it_worked = ERROR;
            continue;
        }
        if (loop_to_find_correct_id(workshop, id_to_delete) != 0) {
            my_printf("ID %d not found.\n", id_to_delete);
            value_to_check_if_it_worked = ERROR;
        }
    }
    return value_to_check_if_it_worked;
}
