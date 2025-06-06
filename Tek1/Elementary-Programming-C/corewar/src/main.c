/*
** EPITECH PROJECT, 2025
** main
** File description:
** main for corewar
*/

#include <unistd.h>
#include "my_lib_functions.h"
#include "macro.h"
#include "args.h"
#include "corewar.h"

static void usage_guide(void)
{
    mini_printf("in usage_guide\n");
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        print_error("Wrong number of args\n");
        return ERROR;
    }
    if (argc == 2 && my_strcmp(argv[1], "-h") == SUCCESS) {
        usage_guide();
        return SUCCESS;
    }
    if (handle_game(argc, argv) == ERROR) {
        return ERROR;
    }
    return SUCCESS;
}
