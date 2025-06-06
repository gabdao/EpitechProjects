/*
** EPITECH PROJECT, 2025
** B-CPE-200-PAR-2-1-corewar-raphael.varichon-dupre
** File description:
** open_champ_file
*/

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "op.h"
#include "my_lib_functions.h"
#include "corewar.h"
#include "macro.h"

static void set_offset(FILE *fd, champions_t *champ, corewar_t *corewar)
{
    int adress = 0;

    fseek(fd, HEADER_SIZE, SEEK_SET);
    fread(champ->code, sizeof(uint8_t), champ->prog_size, fd);
    for (int i = 0; i < champ->prog_size; ++i) {
        adress = (champ->load_adress + i) % MEM_SIZE;
        corewar->arena[adress] = champ->code[i];
    }
    fclose(fd);
}

int open_champ_file(champions_t *champ, corewar_t *corewar)
{
    FILE *fd = NULL;
    header_t header;

    fd = fopen(champ->prog_name, "rb");
    if (!fd) {
        print_error("champion doesnt exist\n");
        return ERROR;
    }
    fread(&header, sizeof(header), 1, fd);
    if (little_to_big_endian(header.magic) != COREWAR_EXEC_MAGIC) {
        print_error("magic wrong\n");
        fclose(fd);
        return ERROR;
    }
    champ->prog_size = little_to_big_endian(header.prog_size);
    my_strcpy(champ->prog_name, header.prog_name);
    my_strcpy(champ->comment, header.comment);
    set_offset(fd, champ, corewar);
    return SUCCESS;
}
