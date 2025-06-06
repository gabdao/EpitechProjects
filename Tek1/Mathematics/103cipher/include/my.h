/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** header for mylib
*/
#include <stdarg.h>
#ifndef MY_H
    #define MY_H

//Functions to handle Key matrice
static int calculate_dimensions_for_matrice(char *key, int size_key);
static int **key_to_ascii_in_matrice(
    int **matrice,
    int dimension_matrice,
    int size_key,
    char *key);
static int get_value_for_matrice(int index, int size_key, char *key);
int **key_to_matrice(char *key);
static void print_matrice(int **matrice, int dimension_matrice);
static void free_matrice(int **matrice, int dimension_matrice);

#endif
