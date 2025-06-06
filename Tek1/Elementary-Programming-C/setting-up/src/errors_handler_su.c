/*
** EPITECH PROJECT, 2024
** setting_up errors handler
** File description:
** Projet setting_up errors handler
*/
#include "my.h"
#include "my_macro.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int print_errors_messages(const char *message)
{
    write(2, message, my_strlen(message));
    return ERROR;
}

static int ignore_fst_line(char *buffer)
{
    int i = 0;

    while (buffer[i] != '\n' && buffer[i] != '\0') {
        i++;
    }
    if (buffer[i] == '\0') {
        return ERROR;
    }
    return i + 1;
}

int check_if_at_least_one_line(char *buffer)
{
    int i = ignore_fst_line(buffer);

    if (i == ERROR) {
        return print_errors_messages("Error: First line not terminated\n");
    }
    for (; buffer[i] != '\0'; i++) {
        if (buffer[i] != '\n' && buffer[i] != '\r') {
            return SUCCESS;
        }
    }
    return print_errors_messages("Error: No lines found after first line\n");
}

static int get_first_line_length(char *buffer)
{
    int i = ignore_fst_line(buffer);
    int line_len = 0;

    if (i == ERROR) {
        return print_errors_messages("Error: First line not terminated\n");
    }
    while (buffer[i + line_len] != '\n' && buffer[i + line_len] != '\0')
        line_len++;
    return line_len;
}

static int compare_line_lengths(char *buffer, int start, int prev_length)
{
    int current_length = 0;

    for (int j = start; buffer[j] != '\0'; j++) {
        if (buffer[j] == '\r')
            continue;
        if (buffer[j] != '\n') {
            current_length++;
            continue;
        }
        if (prev_length != 0 && current_length != prev_length) {
            return print_errors_messages("Error: different lines length\n");
        }
        prev_length = current_length;
        current_length = 0;
    }
    return SUCCESS;
}

static int check_lines_length(char *buffer)
{
    int line_len = get_first_line_length(buffer);
    int start = ignore_fst_line(buffer) + line_len + 1;

    return compare_line_lengths(buffer, start, line_len);
}

static int check_first_line_if_is_nb_lines(char *buffer)
{
    int i = 0;

    if (buffer[CHARACTER_FIRST] == '\n' || buffer[CHARACTER_FIRST] == '\0') {
        return print_errors_messages("Error: First line is invalid\n");
    }
    for (; buffer[i] != '\n' && buffer[i] != '\0'; i++) {
        if (!my_is_digit(buffer[i])) {
            return print_errors_messages("Character forbidden on 1st line\n");
        }
    }
    if (buffer[i] != '\n') {
        return print_errors_messages("Error:Missing newline after 1st line\n");
    }
    return SUCCESS;
}

static int check_characters(char *buffer_to_check)
{
    int i = ignore_fst_line(buffer_to_check);

    if (i == ERROR) {
        return print_errors_messages("Error: First line not terminated\n");
    }
    for (i; buffer_to_check[i] != '\0'; i++) {
        if (buffer_to_check[i] == '\0') {
            continue;
        }
        if (buffer_to_check[i] == '\n') {
            continue;
        }
        if (buffer_to_check[i] == ' ') {
            continue;
        }
        if (buffer_to_check[i] != '.' && buffer_to_check[i] != 'o') {
            return print_errors_messages("Forbidden characters in the file\n");
        }
    }
    return SUCCESS;
}

int check_lines_terminated(char *buffer)
{
    int i = ignore_fst_line(buffer);

    if (i == ERROR) {
        return print_errors_messages("Error: First line not terminated\n");
    }
    for (; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\r') {
            continue;
        }
        if (buffer[i] == '\n') {
            continue;
        }
        while (buffer[i] != '\n' && buffer[i] != '\0') {
            i++;
        }
        if (buffer[i] != '\n') {
            return print_errors_messages("Error: Line needs '\\n'\n");
        }
    }
    return SUCCESS;
}

int errors_handler(char *buffer)
{
    if (check_first_line_if_is_nb_lines(buffer) == ERROR) {
        return ERROR;
    }
    if (check_if_at_least_one_line(buffer) == ERROR) {
        return ERROR;
    }
    if (check_characters(buffer) == ERROR) {
        return ERROR;
    }
    if (check_lines_length(buffer) == ERROR) {
        return ERROR;
    }
    if (check_lines_terminated(buffer) == ERROR) {
        return ERROR;
    }
    return SUCCESS;
}
