/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** my_str_to_word_array.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my_lib_functions.h"

bool find_spt(char *spt, char c)
{
    for (int i = 0; spt[i] != '\0'; i++) {
        if (c == spt[i] || c == '\0')
            return true;
    }
    return false;
}

int wordlen(char const *str, int i, char *spt)
{
    int count = 0;

    while (!find_spt(spt, str[i])) {
        count++;
        i++;
    }
    return count;
}

static int separator_counter(char *str, char *spt)
{
    int count = 0;
    int i = 0;
    int len = my_strlen(str);

    for (i = 0; i < len; i++) {
        if (!find_spt(spt, str[i]) && (i == 0 || find_spt(spt, str[i - 1])))
            count++;
    }
    return count;
}

static char *retrieve_words(char *str, int index, int nb_char)
{
    char *word = malloc(sizeof(char) * (nb_char + 1));

    if (word == NULL)
        return NULL;
    for (int i = 0; i < nb_char; i++) {
        word[i] = str[index + i];
    }
    word[nb_char] = '\0';
    return word;
}

char **my_str_to_word_array(char *str, char *spt)
{
    int spt_count = separator_counter(str, spt);
    char **array = malloc(sizeof(char *) * (spt_count + 1));
    int index = 0;
    int len = 0;

    if (array == NULL || str == NULL)
        return NULL;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!find_spt(spt, str[i])) {
            len = wordlen(str, i, spt);
            array[index] = retrieve_words(str, i, len);
            index++;
            i += len - 1;
        }
    }
    array[index] = NULL;
    return array;
}
