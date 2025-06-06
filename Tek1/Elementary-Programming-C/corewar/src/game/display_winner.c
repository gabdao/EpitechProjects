/*
** EPITECH PROJECT, 2025
** display winner
** File description:
** display
*/

#include "corewar.h"
#include "my_lib_functions.h"

static champions_t *find_champion_by_id(args_t *args, int id)
{
    for (size_t i = 0; i < args->nb_champions; ++i) {
        if (args->champions[i].prog_number == id)
            return &args->champions[i];
    }
    return NULL;
}

int display_winner(corewar_t *corewar, args_t *args)
{
    champions_t *winner = find_champion_by_id(args, corewar->last_live_id);

    if (winner == NULL) {
        mini_printf("No winner could be determined.\n");
        return ERROR;
    }
    mini_printf("The player %d(%s) has won.\n",
        winner->prog_number, winner->prog_name);
    return SUCCESS;
}
