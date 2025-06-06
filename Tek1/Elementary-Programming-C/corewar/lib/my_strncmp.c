/*
** EPITECH PROJECT, 2024
** my_strncmp
** File description:
** my_strncmp
*/

#include <stddef.h>
#include "my_lib_functions.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int nb = 0;

    if (s1 == NULL || s2 == NULL)
        return -1;
    if (my_strlen(s1) < my_strlen(s2))
        return -1;
    if (my_strlen(s1) > my_strlen(s2))
        return 1;
    for (int i = n; s1[i] != '\0' && s2[i] != '\0'; i--) {
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
