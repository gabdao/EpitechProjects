/*
** EPITECH PROJECT, 2024
** My_radar
** File description:
** handling script files
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "macro.h"
#include "handling_script_files.h"
#include "my_lib.h"

static int check_args(int argc, char **argv)
{
    int len = strlen(argv[1]);

    if (argc != 2) {
        fprintf(stderr, "Wrong number of arguments\n");
        return ERROR;
    }
    if (len < 4 || argv[1][len - 4] != '.' ||
        argv[1][len - 3] != 'r' ||
        argv[1][len - 2] != 'd' ||
        argv[1][len - 1] != 'r') {
        fprintf(stderr, "The file must finish by .rdr\n");
        return ERROR;
    }
    return SUCCESS;
}

char *read_file_to_string(FILE *file)
{
    char *content;
    long length;

    fseek(file, 0, SEEK_END);
    length = ftell(file);
    rewind(file);
    content = malloc(length + 1);
    if (!content) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        return NULL;
    }
    fread(content, 1, length, file);
    content[length] = '\0';
    return content;
}

static char **read_and_split_file(FILE *file)
{
    char *file_content;
    char **lines;

    file_content = read_file_to_string(file);
    if (!file_content)
        return NULL;
    lines = my_str_to_word_array_su(file_content);
    free(file_content);
    return lines;
}

static void print_lines(char **lines)
{
    for (int i = 0; lines[i]; i++) {
        printf("Line %d: %s\n", i, lines[i]);
        free(lines[i]);
    }
    free(lines);
}

int handling_script_files(int argc, char **argv)
{
    FILE *file;
    char **lines;

    if (check_args(argc, argv) == ERROR) {
        return ERROR;
    }
    file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
        return ERROR;
    }
    lines = read_and_split_file(file);
    fclose(file);
    if (!lines)
        return ERROR;
    print_lines(lines);
    return SUCCESS;
}
