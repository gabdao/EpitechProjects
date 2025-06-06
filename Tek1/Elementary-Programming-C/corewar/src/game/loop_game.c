/*
** EPITECH PROJECT, 2025
** loop game
** File description:
** loop game
*/

#include <unistd.h>
#include <stdbool.h>
#include "macro.h"
#include "my_lib_functions.h"
#include "args.h"
#include "corewar.h"
#include "op.h"

static int init_corewar(corewar_t *corewar, UNUSED args_t *args)
{
    corewar->cycle = 0;
    corewar->cycle_to_die = CYCLE_TO_DIE;
    corewar->last_live_id = -1;
    return SUCCESS;
}

static bool is_game_over(corewar_t *corewar)
{
    if (corewar->process_list == NULL) {
        return true;
    } else {
        return false;
    }
}

static void destroy_corewar(corewar_t *corewar)
{
    (void)corewar;
}

static int end_loop(bool is_dump, corewar_t *corewar, args_t *args)
{
    if (is_dump) {
        dump_memory(corewar);
        return SUCCESS;
    }
    display_winner(corewar, args);
    destroy_corewar(corewar);
    return SUCCESS;
}

int loop_game(args_t *args, corewar_t *corewar)
{
    bool is_dump = false;

    init_corewar(corewar, args);
    init_processes(args, corewar);
    while (!is_game_over(corewar)) {
        corewar->cycle++;
        update_all_processes(corewar);
        handle_instruction_effects(corewar, args);
        if (corewar->cycle == args->dump_nb_cycle) {
            is_dump = true;
            break;
        }
        if (corewar->cycle_to_die != 0 &&
            corewar->cycle % corewar->cycle_to_die == 0)
            check_cycle_to_die(corewar);
    }
    end_loop(is_dump, corewar, args);
    return SUCCESS;
}
