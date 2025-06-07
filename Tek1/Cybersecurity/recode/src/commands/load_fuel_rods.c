/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** load_fuel_rods
*/

#include <stdio.h>

static void nb_fuel_is_valid(int nb_rods)
{
    int fuel_rods[10];

    for (int j = 0; j < nb_rods; j++) {
        fuel_rods[j] = j + 1;
        printf("Fuel rod %d loaded.\n", fuel_rods[j]);
        sleep(1);
    }
    return;
}

static int init_rods(char *input, int nb_input)
{
    char *endptr;

    printf("Loading fuel rods...\n");
    printf("Enter the number of fuel rods to load (max 10): ");
    fgets(input, 100, stdin);
    nb_input = strtol(input, &endptr, 10);
    return nb_input;
}

void load_fuel_rods(void)
{
    int nb_input = 0;
    char input[100];
    char secret_key[28] = "{The secret stone is here !}";

    nb_input = init_rods(input, nb_input);
    if (nb_input > 10) {
        printf("Error: Too many fuel rods!\n");
        return;
    }
    if (nb_input < 10 && nb_input > 0) {
        nb_fuel_is_valid(nb_input);
        return;
    } else {
        fprintf(stderr, "nb of rods cant be negative\n");
        return;
    }
    if (strcmp(secret_key, "{The secret stone is here !}")) {
        printf("\nSensitive Data:\n");
        printf("Secret Key: %s\n", secret_key);
    }
}
