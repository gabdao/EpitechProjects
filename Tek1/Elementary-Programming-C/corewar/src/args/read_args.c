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
#include "utils.h"

// void print_data_structures(args_t *args)
// {
//     mini_printf("nb cycle is : %d\n", args->dump_nb_cycle);
//     for (size_t i = 0; i < args->nb_champions; ++i) {
//         mini_printf("champion's name : %s\n", args->champions[i].prog_name);
//         mini_printf("   ");
//         mini_printf("prog_number is :
//         %d\n", args->champions[i].prog_number);
//         mini_printf("   ");
//         if (args->champions[i].load_adress)
//             mini_printf("load adresse is : %d\n",
//             args->champions[i].load_adress);
//         else
//             mini_printf("load adresse is : NULL\n");
//         mini_printf("\n");
//     }
//     return;
// }

static void handle_flag_n(int argc, char **argv, int *i, flags_t *flag)
{
    if (my_strcmp(argv[*i], "-n") == SUCCESS && *i + 1 < argc) {
        ++(*i);
        flag->temp_prog_number = my_atoi(argv[*i]);
    }
}

static void handle_flag_a(int argc, char **argv, int *i, flags_t *flag)
{
    if (my_strcmp(argv[*i], "-a") == SUCCESS && *i + 1 < argc) {
        ++(*i);
        flag->temp_load_address = my_atoi(argv[*i]);
    }
}

static int handle_cor_files(char **argv, args_t *args, flags_t flag, int i)
{
    int index = 0;

    if (args->nb_champions >= MAX_CHAMPIONS) {
        print_error("cant handle more than 4 champions\n");
        return ERROR;
    }
    index = args->nb_champions;
    args->champions[index].prog_name = argv[i];
    args->champions[index].prog_number = flag.temp_prog_number;
    args->champions[index].load_adress = flag.temp_load_address;
    ++args->nb_champions;
    return SUCCESS;
}

static int handle_cor(char **argv, args_t *args, flags_t *flag, int i)
{
    if (is_dot_cor_file(argv[i])) {
        if (handle_cor_files(argv, args, *flag, i) == ERROR)
        return ERROR;
        flag->temp_prog_number = -1;
        flag->temp_load_address = -1;
    }
    return SUCCESS;
}

static int parse_champion_args(int argc, char **argv, args_t *args)
{
    flags_t flag;
    int i = 1;

    flag.temp_load_address = -1;
    flag.temp_prog_number = -1;
    for (; i < argc; ++i) {
        handle_flag_n(argc, argv, &i, &flag);
        handle_flag_a(argc, argv, &i, &flag);
        if (handle_cor(argv, args, &flag, i) == ERROR)
            return ERROR;
    }
    return SUCCESS;
}

int detect_args(int argc, char **argv, args_t *args)
{
    if (init_args(argc, argv, args) == ERROR)
        return ERROR;
    if (parse_champion_args(argc, argv, args) == ERROR)
        return ERROR;
    handle_default_values(args);
    return SUCCESS;
}
