/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** my_strcmp
*/

#include "my_lib_functions.h"

int my_strcmp(char const *s1, char const *s2)
{
    int nb = 0;

    if (s1 == NULL || s2 == NULL)
        return -1;
    if (my_strlen(s1) < my_strlen(s2))
        return -1;
    if (my_strlen(s1) > my_strlen(s2))
        return 1;
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] < s2[i]) {
            nb = s2[i] - s1[i];
            return nb;
        }
        if (s1[i] > s2[i]) {
            nb = s1[i] - s2[i];
            return nb;
        }
    }
    return 0;
}
