/*
** EPITECH PROJECT, 2025
** header args
** File description:
** header for arguments
*/

#ifndef _ARGS_H
    #define _ARGS_H

    #include "all.h"
    #include "macro.h"

typedef struct flags_s {
    int temp_prog_number;
    int temp_load_address;
} flags_t;

typedef struct champions_s {
    char *prog_name;
    int prog_number;
    int load_adress;
    //data from header
    char comment[COMMENT_LENGTH + 1];
    int prog_size;
    uint8_t code[CHAMP_MAX_SIZE];
} champions_t;

typedef struct args_s {
    size_t nb_champions;
    champions_t champions[MAX_CHAMPIONS + 1];
    size_t dump_nb_cycle;
} args_t;

//Args
int init_args(int argc, char **argv, args_t *args);
int detect_args(int argc, char **argv, args_t *args);
void handle_default_values(args_t *args);

#endif /* _ARGS_H */
