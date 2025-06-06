/*
** EPITECH PROJECT, 2025
** init processes
** File description:
** init processes
*/

#include "macro.h"
#include "my_lib_functions.h"
#include "args.h"
#include "corewar.h"
#include "op.h"
#include <stdlib.h>

// void debug_print_processes(process_t *list)
// {
//     int id = 1;

//     while (list) {
//         mini_printf("---- Process %d ----\n", id);
//         mini_printf("pc               : %d\n", list->pc);
//         mini_printf("owner ID         : %d\n", list->owner_id);
//         mini_printf("carry            : %d\n", list->carry);
//         mini_printf("cycles to wait   : %d\n", list->cycles_to_wait);
//         mini_printf("last live cycle  : %d\n", list->last_live_cycle);
//         for (int i = 0; i < REG_NUMBER; ++i)
//             mini_printf("r[%d] = %d\n", i, list->reg[i]);
//         list = list->next;
//         id++;
//     }
// }

static process_t *allocate_process(void)
{
    process_t *new = malloc(sizeof(process_t));

    if (!new) {
        print_error("couldn't allocate memory for process");
        return NULL;
    }
    new->next = NULL;
    return new;
}

static void fill_process(process_t *proc, champions_t *champion)
{
    proc->pc = champion->load_adress;
    proc->owner_id = champion->prog_number;
    proc->carry = -1;
    proc->cycles_to_wait = -1;
    proc->last_live_cycle = -1;
    for (int i = 0; i < REG_NUMBER; ++i)
        proc->reg[i] = 0;
    proc->reg[0] = champion->prog_number;
}

static void append_process(process_t **head, process_t *new)

{
    process_t *temp = NULL;

    if (*head == NULL) {
        *head = new;
        return;
    }
    temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = new;
}

int init_processes(args_t *args, corewar_t *corewar)
{
    process_t *new = NULL;

    corewar->process_list = NULL;
    for (size_t i = 0; i < args->nb_champions; ++i) {
        new = allocate_process();
        if (!new)
            return ERROR;
        fill_process(new, &args->champions[i]);
        append_process(&corewar->process_list, new);
    }
    return SUCCESS;
}
