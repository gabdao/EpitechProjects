/*
** EPITECH PROJECT, 2024
** my_str_to_word_array_su
** File description:
** Function that convert string in a **char
*/
#include <stddef.h>
#include "../../include/my.h"
#include <stdio.h>
#include <stdlib.h>

char *manage_string_null(char const *str)
{
    if (str == NULL || str[0] == '\0') {
        my_printf("String is NULL\n");
    }
    return NULL;
}

int count_lines(const char *str)
{
    int count_lines = 1;
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if (str[i] == '\n') {
            count_lines++;
        }
    }
    return count_lines;
}

char *copy_substring(char const *str, int start, int end)
{
    int len = end - start;
    char *new_str = malloc(len + 1);

    if (new_str == NULL) {
        return NULL;
    }
    for (int i = 0; i < len; i++) {
        new_str[i] = str[start + i];
    }
    new_str[len] = '\0';
    return new_str;
}

char **copy_lines_in_new_array(const char *str, char **array_from_str)
{
    int len = my_strlen(str);
    int line_index = 0;
    int start = 0;

    for (int i = 0; i <= len; i++) {
        if (str[i] == '\n' || str[i] == '\0') {
            array_from_str[line_index] = copy_substring(str, start, i);
            line_index++;
            start = i + 1;
        }
    }
    array_from_str[line_index] = NULL;
    return array_from_str;
}

char **my_str_to_word_array_su(char const *str)
{
    char **array_from_str;
    int nb_lines;

    manage_string_null(str);
    nb_lines = count_lines(str);
    array_from_str = malloc((nb_lines + 1) * sizeof(char *));
    if (array_from_str == NULL) {
    return NULL;
    }
    copy_lines_in_new_array(str, array_from_str);
    return array_from_str;
}
