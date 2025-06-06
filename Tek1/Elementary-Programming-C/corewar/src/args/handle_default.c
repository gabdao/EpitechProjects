/*
** EPITECH PROJECT, 2025
** reader
** File description:
** reading args and parsing
*/

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include "macro.h"
#include "my_lib_functions.h"
#include "args.h"

int init_args(int argc, char **argv, args_t *args)
{
    int found = -1;

    for (int i = 1; i < argc; ++i) {
        if (my_strcmp(argv[i], "-dump") == SUCCESS && i + 1 < argc) {
            args->dump_nb_cycle = my_atoi(argv[i + 1]);
            found = SUCCESS;
        }
    }
    if (found != SUCCESS) {
        print_error("flag dump is mandatory\n");
        return ERROR;
    }
    args->nb_champions = 0;
    for (size_t i = 0; i < MAX_CHAMPIONS; ++i) {
        args->champions[i].prog_name = NULL;
        args->champions[i].prog_number = -1;
        args->champions[i].load_adress = -1;
    }
    return SUCCESS;
}

static int is_prog_number_used(int *used_numbers, int number)
{
    int i = 0;

    for (i = 0; i < MAX_CHAMPIONS; ++i) {
        if (used_numbers[i] == number)
            return 1;
    }
    return SUCCESS;
}

static void first_free_number(champions_t *champ, int *used_numbers, int index)
{
    int default_number = 1;

    for (; default_number <= MAX_CHAMPIONS; ++default_number) {
        if (!is_prog_number_used(used_numbers, default_number)) {
            champ->prog_number = default_number;
            used_numbers[index] = default_number;
            return;
        }
    }
}

void handle_default_values(args_t *args)
{
    int used_numbers[MAX_CHAMPIONS + 1] = {0};

    for (size_t i = 0; i < args->nb_champions; ++i) {
        used_numbers[i] = args->champions[i].prog_number;
    }
    for (size_t i = 0; i < args->nb_champions; ++i) {
        if (args->champions[i].prog_number == -1) {
            first_free_number(&args->champions[i], used_numbers, i);
        }
        if (args->champions[i].load_adress == -1) {
            args->champions[i].load_adress = (MEM_SIZE / args->nb_champions)
            * i;
        }
    }
}
