/*
** EPITECH PROJECT, 2025
** get arg type
** File description:
** get arg type
*/

#include "utils.h"

int get_arg_type(uint8_t coding_byte, int index)
{
    return (coding_byte >> (6 - index * 2)) & 0b11;
}
