/*
** EPITECH PROJECT, 2025
** header
** File description:
** header for utils functions
*/

#ifndef _MY_UTILS_H
    #define _MY_UTILS_H
    #include <stdbool.h>
    #include <stdint.h>
    #include "corewar.h"
bool is_dot_cor_file(const char *filename);
bool has_coding_byte(uint8_t opcode);
int get_arg_type(uint8_t coding_byte, int index);
void write_int_to_arena(corewar_t *corewar, int address, int value);
int read_int_from_arena(corewar_t *corewar, int address);

#endif /* _MY_UTILS_H */
