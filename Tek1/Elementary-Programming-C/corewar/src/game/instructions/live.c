/*
** EPITECH PROJECT, 2025
** live instructions
** File description:
** live instruction
*/

#include "corewar.h"
#include "my_lib_functions.h"

static void print_player_alive(int player_id, args_t *args)
{
    for (size_t i = 0; i < args->nb_champions; ++i) {
        if (args->champions[i].prog_number == player_id) {
            mini_printf("The player %d(%s) is alive.\n",
                player_id, args->champions[i].prog_name);
            return;
        }
    }
}

void mnemo_live(corewar_t *corewar, process_t *proc, args_t *args)
{
    proc->last_live_cycle = corewar->cycle;
    corewar->last_live_id = proc->owner_id;
    corewar->nbr_live++;
    print_player_alive(proc->owner_id, args);
}
