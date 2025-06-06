/*
** EPITECH PROJECT, 2024
** 104neutrinos
** File description:
** 104neutrinos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <ctype.h>
#include "my.h"
#include "my_macro.h"

static int handle_next_value(void)
{
    char buffer[1000];
    int enter_value = 0;

    printf("Enter next value: ");
    fflush(stdout);
    scanf("%[^\n]", buffer);
    getchar();
    if (strcmp(buffer, "END") == 0) {
        return -1;
    }
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (i == 0 && buffer[i] == '-')
            continue;
        if (!isdigit(buffer[i])) {
            fprintf(stderr, "Error: next value is not a number\n");
            return 84;
        }
    }
    enter_value = atoi(buffer);
    return enter_value;
}

static void display_calculs(stats_t *stats, int value_given)
{
    double rms = calculate_rms(value_given, &stats->a_mean, &stats->sd,
    stats->n);

    disp_nb_values(&stats->n);
    disp_stand_deviation(value_given, stats->n, &stats->a_mean, &stats->sd);
    disp_arithmetic_mean(&stats->a_mean, value_given, stats->n);
    printf("    Root mean square: %.2f\n", rms);
    disp_harmonic_mean(value_given, &stats->n, &stats->harmonic_mean);
    printf("\n");
}

static int handle_display(int argc, char **argv)
{
    int value_given = 0;
    stats_t stats;

    stats.n = atoi(argv[1]);
    stats.a_mean = atof(argv[2]);
    stats.harmonic_mean = atof(argv[3]);
    stats.sd = atof(argv[4]);
    while (1) {
        value_given = handle_next_value();
        if (value_given == -1) {
            printf("Program terminated.\n");
            break;
        }
        if (value_given == 84) {
            return 84;
        }
        display_calculs(&stats, value_given);
    }
    return 0;
}

static int usage_tutorial(void)
{
    printf("\033[1mUSAGE\033[0m\n");
    printf("    ./104neutrinos n a h sd\n\n");
    printf("\033[1mDESCRIPTION\033[0m\n");
    printf("    %-4s %s\n", "n", "number of values");
    printf("    %-4s %s\n", "a", "arithmetic mean");
    printf("    %-4s %s\n", "h", "harmonic mean");
    printf("    %-4s %s\n", "sd", "standard deviation");
    return 0;
}

static int is_valid_int(const char *str)
{
    int i = 0;

    if (str[i] == '-') {
        i++;
    }
    for (; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    if (i == 0 || (str[0] == '-' && i == 1)) {
        return 0;
    }
    return 1;
}

static int check_args(int argc, char **argv)
{
    if (argc != 5) {
        fprintf(stderr, "Error: Invalid number of arguments\n");
        return 84;
    }
    if (argv[1][0] == '-') {
        fprintf(stderr, "Error: n can not be a negative value\n");
        return 84;
    }
    for (int i = 1; i < argc; i++) {
        if (!is_valid_int(argv[i])) {
            fprintf(stderr, "Error: Argument '%s' is not a valid integer\n",
            argv[i]);
            return 84;
        }
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        usage_tutorial();
        return 0;
    }
    if (check_args(argc, argv) == 84) {
    return 84;
    }
    handle_display(argc, argv);
    return 0;
}
