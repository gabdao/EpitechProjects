/*
** EPITECH PROJECT, 2025
** handling parser
** File description:
** file to handle parsing
*/

#include "my_lib_functions.h"
#include "op.h"
#include "robot_factory.h"
#include "my_macro.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

static int check_header_or_body(
    char *line,
    char **parsed_line,
    header_t *header,
    body_t **body_list)
{
    char **header_data = my_str_to_word_array(line, "\"");

    if (my_strcmp(parsed_line[0], NAME_CMD_STRING) == 0
        && check_name_errors(header_data) == SUCCESS) {
        my_strcpy(header->prog_name, header_data[1]);
        my_free_array(header_data);
        return SUCCESS;
    }
    if (my_strcmp(parsed_line[0], COMMENT_CMD_STRING) == 0
        && check_name_errors(header_data) == SUCCESS) {
        my_strcpy(header->comment, header_data[1]);
        my_free_array(header_data);
        return SUCCESS;
    }
    if (handling_body(parsed_line, body_list) == ERROR) {
        my_free_array(header_data);
        return ERROR;
    }
    my_free_array(header_data);
    return SUCCESS;
}

static int loop_condition(
    char *line,
    char **parsed_line,
    header_t *header,
    body_t **body_list)
{
    if (parsed_line == NULL || parsed_line[0] == NULL) {
        my_free_array(parsed_line);
        return SUCCESS;
    }
    if (parsed_line[0][0] == COMMENT_CHAR) {
        mini_printf("comment found\n");
        my_free_array(parsed_line);
        return SUCCESS;
    }
    if (check_header_or_body(line, parsed_line, header, body_list) == ERROR) {
        my_free_array(parsed_line);
        return ERROR;
    }
    my_free_array(parsed_line);
    return SUCCESS;
}

static int loop_get_file(FILE *fd, header_t *header, body_t **body_list)
{
    ssize_t read;
    size_t buffer = 0;
    char *line = NULL;
    char **parsed_line = NULL;

    read = getline(&line, &buffer, fd);
    while (read != -1) {
        parsed_line = my_str_to_word_array(line, "\t\n, ");
        if (loop_condition(line, parsed_line, header, body_list) == ERROR) {
            free(line);
            return ERROR;
        }
        read = getline(&line, &buffer, fd);
    }
    free(line);
    return SUCCESS;
}

int send_each_line_file(char *file)
{
    FILE *fd = NULL;
    header_t header = {0};
    body_t *body_list = NULL;

    fd = fopen(file, "r");
    if (!fd) {
        return print_error_message("Couldnt open file\n");
    }
    if (loop_get_file(fd, &header, &body_list) == ERROR) {
        fclose(fd);
        free_body_list(body_list);
        return ERROR;
    }
    fd = header_writing(header, body_list);
    body_writing_handling(body_list, fd);
    free_body_list(body_list);
    fclose(fd);
    return SUCCESS;
}
