/*
** EPITECH PROJECT, 2025
** handle game
** File description:
** file to handle game
*/

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include "macro.h"
#include "my_lib_functions.h"
#include "args.h"
#include "corewar.h"
#include "op.h"

int handle_game(int argc, char **argv)
{
    args_t *args = malloc(sizeof(args_t));
    corewar_t *corewar = malloc(sizeof(corewar_t));

    corewar->arena = malloc(sizeof(uint8_t) * MEM_SIZE);
    if (!corewar->arena || !args)
        return ERROR;
    if (detect_args(argc, argv, args) == ERROR) {
        return ERROR;
    }
    for (size_t i = 0; i < args->nb_champions; ++i) {
        if (open_champ_file(&args->champions[i], corewar) == ERROR)
            return ERROR;
    }
    loop_game(args, corewar);
    return SUCCESS;
}
