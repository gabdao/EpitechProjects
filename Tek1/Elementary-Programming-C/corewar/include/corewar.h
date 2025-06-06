/*
** EPITECH PROJECT, 2025
** header corewar
** File description:
** header for corewar
*/

#ifndef _COREWAR_H
    #define _COREWAR_H

    #include "all.h"
    #include "op.h"
    #include "args.h"

typedef struct process_s {
    int id;
    int pc;
    int reg[REG_NUMBER];
    int coding_byte;
    int carry;
    int cycles_to_wait;
    int last_live_cycle;
    int owner_id;
    struct process_s *next;
} process_t;

typedef struct corewar_s {
    process_t *process_list;
    size_t cycle;
    int cycle_to_die;
    int last_live_id;
    int nbr_live;
    uint8_t *arena;
} corewar_t;

typedef struct arg_types_s {
    int arg1;
    int arg2;
    int arg3;
} arg_types_t;

// Instructions
void mnemo_live(corewar_t *corewar, process_t *proc, args_t *args);
void mnemo_ld(corewar_t *corewar, process_t *proc, args_t *args);
void mnemo_st(corewar_t *corewar, process_t *proc, args_t *args);
void mnemo_add(corewar_t *corewar, process_t *proc, args_t *args);
void mnemo_sub(corewar_t *corewar, process_t *proc, args_t *args);
void mnemo_and(corewar_t *corewar, process_t *proc, args_t *args);
void mnemo_or(corewar_t *corewar, process_t *proc, args_t *args);
void mnemo_xor(corewar_t *corewar, process_t *proc, args_t *args);
void mnemo_zjmp(corewar_t *corewar, process_t *proc, args_t *args);
void mnemo_ldi(corewar_t *corewar, process_t *proc, args_t *args);
void mnemo_sti(corewar_t *corewar, process_t *proc, args_t *args);
void mnemo_fork(corewar_t *corewar, process_t *proc, args_t *args);
void mnemo_lld(corewar_t *corewar, process_t *proc, args_t *args);
void mnemo_lldi(corewar_t *corewar, process_t *proc, args_t *args);
void mnemo_lfork(corewar_t *corewar, process_t *proc, args_t *args);
void mnemo_aff(corewar_t *corewar, process_t *proc, args_t *args);

// Corewar main loop functions
int handle_game(int argc, char **argv);
int loop_game(args_t *args, corewar_t *corewar);
int open_champ_file(champions_t *champ, corewar_t *corewar);
int init_processes(args_t *args, corewar_t *corewar);
int update_all_processes(corewar_t *corewar);
int handle_instruction_effects(corewar_t *corewar, args_t *args);
int check_cycle_to_die(corewar_t *corewar);
void dump_memory(corewar_t *corewar);
int display_winner(corewar_t *corewar, args_t *args);

// Utility
int little_to_big_endian(int little_nb);

#endif /* _COREWAR_H */
