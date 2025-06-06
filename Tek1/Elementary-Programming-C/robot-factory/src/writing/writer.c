/*
** EPITECH PROJECT, 2025
** handling writer
** File description:
** file to handle writer
*/

#include "my_lib_functions.h"
#include "robot_factory.h"
#include "my_macro.h"
#include "op.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char *get_prog_name(header_t header, char *full_name)
{
    char *prog_name = NULL;

    prog_name = header.prog_name;
    full_name = malloc(my_strlen(prog_name) * sizeof(char) + LEN_COR + 1);
    if (full_name == NULL)
        return NULL;
    my_strcpy(full_name, prog_name);
    if (full_name[0] >= 'A' && full_name[0] <= 'Z') {
        full_name[0] += 32;
    }
    my_strcat(full_name, ".cor");
    return full_name;
}

FILE *header_writing(header_t header, body_t *body)
{
    FILE *fp = NULL;
    char *full_name = NULL;

    header.prog_size = little_to_big_endian(get_prog_size(&body));
    mini_printf("DEBUG : %d\n", header.prog_size);
    full_name = get_prog_name(header, full_name);
    header.magic = little_to_big_endian(COREWAR_EXEC_MAGIC);
    fp = fopen(full_name, "wb");
    fwrite(&header, sizeof(header_t), 1, fp);
    return fp;
}
