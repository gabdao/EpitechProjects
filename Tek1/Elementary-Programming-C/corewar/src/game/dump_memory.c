/*
** EPITECH PROJECT, 2025
** loop game
** File description:
** loop game
*/

#include <unistd.h>
#include "corewar.h"
#include "macro.h"
#include "my_lib_functions.h"

static void write_hex_byte(uint8_t byte)
{
    char hex[] = "0123456789abcdef";
    char out[2];

    out[0] = hex[(byte >> 4) & 0xF];
    out[1] = hex[byte & 0xF];
    my_putchar(out[0]);
    my_putchar(out[1]);
}

static void print_space_between(int j)
{
    if (j != 31)
        my_putstr(" ");
}

void dump_memory(corewar_t *corewar)
{
    for (int i = 0; i < MEM_SIZE; i += 32) {
        my_putstr(" ");
        for (int j = 0; j < 32; ++j) {
            write_hex_byte(corewar->arena[i + j]);
            print_space_between(j);
        }
        my_putstr("\n");
    }
}
