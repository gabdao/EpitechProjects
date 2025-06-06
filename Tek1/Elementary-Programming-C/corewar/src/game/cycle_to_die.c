/*
** EPITECH PROJECT, 2025
** cycle to die
** File description:
** cycle to die
*/

#include "macro.h"
#include "corewar.h"

#include "corewar.h"
#include "my_lib_functions.h"
#include <stdlib.h>

static void remove_dead_process(corewar_t *corewar, process_t **prev,
    process_t **current)
{
    process_t *to_delete = *current;

    if (*prev == NULL) {
        corewar->process_list = (*current)->next;
    } else {
        (*prev)->next = (*current)->next;
    }
    *current = (*current)->next;
    free(to_delete);
}

static bool is_process_dead(corewar_t *corewar, process_t *proc)
{
    int time_diff = corewar->cycle - proc->last_live_cycle;

    if (time_diff > corewar->cycle_to_die)
        return true;
    return false;
}

int check_cycle_to_die(corewar_t *corewar)
{
    process_t *current = corewar->process_list;
    process_t *prev = NULL;

    while (current != NULL) {
        if (is_process_dead(corewar, current)) {
            remove_dead_process(corewar, &prev, &current);
        } else {
            prev = current;
            current = current->next;
        }
    }
    if (corewar->nbr_live >= NBR_LIVE)
        corewar->cycle_to_die -= CYCLE_DELTA;
    corewar->nbr_live = 0;
    return SUCCESS;
}
