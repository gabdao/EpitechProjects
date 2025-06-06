/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** header for mylib
*/
#include <stdarg.h>
#ifndef MY_H
    #define MY_H
typedef struct vector_t {
    double x;
    double y;
    double z;
} vector_t;

struct handle_geometric {
    char flags;
    int (*function_ptr)(double x, double y, double i, double j);
};

static int handle_translation(double x, double y, double i, double j);
static int handle_scaling(double x, double y, double m, double n);
static int handle_rotation(double x, double y, double angle, double unused);
static int handle_reflection(double x, double y, double angle, double unused);
#endif
