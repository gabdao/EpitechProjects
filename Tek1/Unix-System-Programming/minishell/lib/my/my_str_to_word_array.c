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

static int check_new_word(int *in_word, int count_lines)
{
    if (!(*in_word)) {
        *in_word = 1;
        return count_lines + 1;
    }
    return count_lines;
}

int count_lines(const char *str)
{
    int count_lines = 0;
    int len = my_strlen(str);
    int in_word = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] != ' ' && str[i] != '\t') {
            count_lines = check_new_word(&in_word, count_lines);
        } else {
            in_word = 0;
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

static void check_condition(
    char **array_from_str,
    const char *str,
    int *line_index,
    int i)
{
    int start = i - 1;

    if (i == 0) {
        start = 0;
    } else {
        while (start >= 0 && str[start] != ' ' && str[start] != '\t') {
            start--;
        }
        start++;
    }
    if (i > start) {
        array_from_str[*line_index] = copy_substring(str, start, i);
        (*line_index)++;
    }
}

char **copy_lines_in_new_array(const char *str, char **array_from_str)
{
    int len = my_strlen(str);
    int line_index = 0;

    for (int i = 0; i <= len; i++) {
        if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\0') &&
            (i == 0 || (str[i - 1] != ' ' && str[i - 1] != '\t'))) {
            check_condition(array_from_str, str, &line_index, i);
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
