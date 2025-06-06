/*
** EPITECH PROJECT, 2025
** has coding byte
** File description:
** has coding byte
*/

#include <stdint.h>
#include <stdbool.h>

bool has_coding_byte(uint8_t opcode)
{
    if (opcode == 1 || opcode == 9 || opcode == 12 || opcode == 15) {
        return false;
    } else
        return true;
}
