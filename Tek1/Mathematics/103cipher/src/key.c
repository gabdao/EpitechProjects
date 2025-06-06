/*
** EPITECH PROJECT, 2024
** 103cipher key managing file
** File description:
** 103cipher key managing file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include "my.h"
#include "my_macro.h"

static int calculate_dimensions_for_matrice(char *key, int size_key)
{
    int dimension_matrice;

    dimension_matrice = (int)ceil(sqrt(size_key));
    return dimension_matrice;
}

static int get_value_for_matrice(int index, int size_key, char *key)
{
    if (index < size_key) {
        return key[index];
    } else {
        return 0;
    }
}

static int **key_to_ascii_in_matrice(
    int **matrice,
    int dimension_matrice,
    int size_key,
    char *key)
{
    int index;

    for (int i = 0; i < dimension_matrice; i++) {
        for (int j = 0; j < dimension_matrice; j++) {
            index = i * dimension_matrice + j;
            matrice[i][j] = get_value_for_matrice(index, size_key, key);
        }
    }
    return matrice;
}

static void print_matrice(int **matrice, int dimension_matrice)
{
    printf("Key matrix:\n");
    for (int i = 0; i < dimension_matrice; i++) {
        for (int j = 0; j < dimension_matrice; j++) {
            printf("%4d", matrice[i][j]);
        }
        printf("\n");
    }
}

static void free_matrice(int **matrice, int dimension_matrice)
{
    for (int i = 0; i < dimension_matrice; i++) {
        free(matrice[i]);
    }
    free(matrice);
}

int **key_to_matrice(char *key)
{
    int size_key;
    int **matrice;
    int dimension_matrice;
    int **final_matrice;

    size_key = strlen(key);
    dimension_matrice = calculate_dimensions_for_matrice(key, size_key);
    matrice = malloc(dimension_matrice * sizeof(int *));
    for (int i = 0; i < dimension_matrice; i++) {
        matrice[i] = malloc(dimension_matrice * sizeof(int));
    }
    final_matrice = key_to_ascii_in_matrice(
        matrice,
        dimension_matrice,
        size_key,
        key);
    print_matrice(matrice, dimension_matrice);
    free_matrice(matrice, dimension_matrice);
    return matrice;
}
