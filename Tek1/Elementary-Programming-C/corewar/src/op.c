/*
** EPITECH PROJECT, 2025
** op
** File description:
** Definition of op_tab
*/

#include "../include/op.h"
#include "corewar.h"

const op_t op_tab[] = {
    {"live", 1, {T_DIR}, 1, 10,
        "alive", mnemo_live},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5,
        "load", mnemo_ld},
    {"st", 2, {T_REG, T_IND | T_REG}, 3, 5,
        "store", mnemo_st},
    {"add", 3, {T_REG, T_REG, T_REG}, 4, 10,
        "addition", mnemo_add},
    {"sub", 3, {T_REG, T_REG, T_REG}, 5, 10,
        "subtraction", mnemo_sub},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
        "and", mnemo_and},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
        "or", mnemo_or},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
        "xor", mnemo_xor},
    {"zjmp", 1, {T_DIR}, 9, 20,
        "jump if zero", mnemo_zjmp},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
        "load index", mnemo_ldi},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
        "store index", mnemo_sti},
    {"fork", 1, {T_DIR}, 12, 800,
        "fork", mnemo_fork},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10,
        "long load", mnemo_lld},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
        "long load index", mnemo_lldi},
    {"lfork", 1, {T_DIR}, 15, 1000,
        "long fork", mnemo_lfork},
    {"aff", 1, {T_REG}, 16, 2,
        "aff", mnemo_aff},
    {0, 0, {0}, 0, 0, 0, NULL}
};
