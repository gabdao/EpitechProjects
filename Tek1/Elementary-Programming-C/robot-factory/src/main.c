/*
** EPITECH PROJECT, 2025
** main
** File description:
** main for robot factory
*/

#include "my_lib_functions.h"
#include "robot_factory.h"
#include "my_macro.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

static void usage_guide(void)
{
    mini_printf("\033[1mUSAGE\033[0m\n");
    mini_printf("./asm file_name[.s]\n");
    mini_printf("\033[1mDESCRIPTION\033[0m\n");
    mini_printf("file_name file in assembly language to be converted ");
    mini_printf("into file_name.cor, an executable in the Virtual Machine\n");
}

static int check_file_format(char *file)
{
    int len = my_strlen(file);
    char *error_message = "file is not a .s file";

    if (file[len - 1] == 's' && file[len - 2] == '.') {
        return SUCCESS;
    } else {
        write(2, error_message, my_strlen(error_message));
        return ERROR;
    }
    return SUCCESS;
}

int main(int argc, char **argv)
{
    char *file = NULL;

    if (argc != 2)
        return ERROR;
    if (!argv[1]) {
        write(2, "Need a file\n", 13);
        return ERROR;
    }
    if (argv[1] && my_strcmp(argv[1], "-h") == SUCCESS) {
        usage_guide();
        return SUCCESS;
    }
    file = argv[1];
    if (check_file_format(file) == ERROR) {
        return ERROR;
    }
    send_each_line_file(file);
    return 0;
}
