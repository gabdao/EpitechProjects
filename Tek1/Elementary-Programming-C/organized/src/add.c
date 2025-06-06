/*
** EPITECH PROJECT, 2024
** Organized add file
** File description:
** Handling add function
*/

#include "my.h"
#include "shell.h"
#include "my_macro.h"
#include "materials.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static int error_handling(char *str)
{
    write(2, str, my_strlen(str));
    return ERROR;
}

static void delete_virgule(char *str)
{
    int len = my_strlen(str);

    if (len > 0 && str[len - 1] == ',') {
        str[len - 1] = '\0';
    }
}

materials_t *create_material(const char *category, const char *name, int id)
{
    materials_t *new_material;

    new_material = malloc(sizeof(materials_t));
    if (!new_material) {
        return NULL;
    }
    new_material->category = my_strdup(category);
    new_material->name = my_strdup(name);
    new_material->id = id;
    new_material->next = NULL;
    return new_material;
}

static int is_valid_category(const char *category)
{
    int i = 0;

    while (allowed_types[i]) {
        if (my_strcmp(category, allowed_types[i]) == 0) {
            return SUCCESS;
        }
        i++;
    }
    return ERROR;
}

static void insert_material(workshop_t *workshop, materials_t *material)
{
    material->next = workshop->head;
    workshop->head = material;
    workshop->next_id++;
}

static int count_pair_in_argv(char **args)
{
    int count = 0;

    while (args[count]) {
        count++;
    }
    if (count == 0 || (count % 2) != 0) {
        return error_handling("wrong args\n");
    }
    return count;
}

int add(void *data, char **args)
{
    workshop_t *workshop = (workshop_t *)data;
    materials_t *new_material;
    char *category;
    char *name;
    int count = count_pair_in_argv(args);

    for (int i = 0; i < count; i += 2) {
        category = args[i];
        name = args[i + 1];
        delete_virgule(name);
        if (is_valid_category(category) == ERROR)
            return error_handling("Bad types\n");
        new_material = create_material(category, name, workshop->next_id);
        if (!new_material)
            return error_handling("Failed to create new material\n");
        insert_material(workshop, new_material);
        my_printf("%s n°%d - \"%s\" added.\n",
        new_material->category, new_material->id, new_material->name);
    }
    return SUCCESS;
}
