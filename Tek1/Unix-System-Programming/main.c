/*
** EPITECH PROJECT, 2024
** my_ls
** File description:
** Function that imitates the ls sys call
*/
#include "./include/my.h"
#include "./include/my_macro.h"
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

const struct flags_my_ls table_my_ls[] = {
    {'a', handle_my_ls_a},
    {'l', handle_my_ls_l},
    {'R', handle_my_ls_up_r},
    {'d', handle_my_ls_d},
    {'r', handle_my_ls_r},
    {'t', handle_my_ls_t},
};

static int detect_flags(char flag, char **content, int argc, char *argv[])
{
    for (int y = 0; y < NB_FLAGS; y++) {
        if (flag == table_my_ls[y].flags) {
            table_my_ls[y].function_ptr(argc, argv, content);
            break;
        }
    }
    return 0;
}

int passing_data_to_detect(char *flag, char **content, int argc, char *argv[])
{
    for (int i = 0; flag && flag[i] != '\0'; i++) {
        detect_flags(flag[i], content, argc, argv);
    }
    return 0;
}

void handle_no_arguments(char **content)
{
    static char *empty_content[] = {".", NULL};

    for (int i = 0; empty_content[i] != NULL; i++) {
        content[i] = empty_content[i];
    }
    content[CLOSE_CONTENT_NO_ARGS] = NULL;
}

void handle_arguments(int argc, char *argv[], char **content, char **flag)
{
    int content_index = 0;

    if (argc == 2) {
        content[content_index] = ".";
    }
    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            *flag = argv[i] + 1;
        } else {
            content[content_index] = argv[i];
            content_index++;
        }
    }
}

int main(int argc, char *argv[])
{
    char *flag = NULL;
    char **content = malloc(argc * sizeof(char *));

    if (argc == 1) {
        handle_no_arguments(content);
    } else {
        handle_arguments(argc, argv, content, &flag);
    }
    if (flag == NULL) {
        handle_my_ls_no_flags(argc, argv, content);
    } else {
        passing_data_to_detect(flag, content, argc, argv);
    }
    return 0;
}
