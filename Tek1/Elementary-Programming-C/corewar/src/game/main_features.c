/*
** EPITECH PROJECT, 2025
** loop game
** File description:
** loop game
*/

#include "macro.h"
#include "corewar.h"
#include "my_lib_functions.h"

int update_all_processes(corewar_t *corewar)
{
    process_t *proc = corewar->process_list;
    uint8_t opcode;

    while (proc != NULL) {
        opcode = corewar->arena[proc->pc];
        if (proc->cycles_to_wait == -1 && opcode >= 1 && opcode <= 16) {
            proc->cycles_to_wait = op_tab[opcode - 1].nbr_cycles;
        }
        if (proc->cycles_to_wait > 0) {
            proc->cycles_to_wait--;
        }
        proc = proc->next;
    }
    return SUCCESS;
}

static void execute_if_live(corewar_t *corewar, process_t *proc, args_t *args)
{
    uint8_t opcode = corewar->arena[proc->pc];

    if (opcode == 0x01) {
        mnemo_live(corewar, proc, args);
    }
    proc->pc = (proc->pc + 1) % MEM_SIZE;
}

int handle_instruction_effects(corewar_t *corewar, args_t *args)
{
    process_t *proc = corewar->process_list;

    while (proc != NULL) {
        execute_if_live(corewar, proc, args);
        proc = proc->next;
    }
    return SUCCESS;
}
