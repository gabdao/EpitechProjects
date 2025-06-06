/*
** EPITECH PROJECT, 2024
** materials.h
** File description:
** header for materials
*/

#ifndef MATERIAL_H
    #define MATERIAL_H

typedef struct materials {
    char *category;
    char *name;
    int id;
    struct materials *next;
} materials_t;

typedef struct workshop {
    materials_t *head;
    int next_id;
} workshop_t;

static const char *allowed_types[] = {
    "WIRE",
    "ACTUATOR",
    "DEVICE",
    "PROCESSOR",
    "SENSOR"
};

#endif
