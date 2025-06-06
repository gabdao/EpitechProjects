/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** Function that compares two strings charcaters by character
*/

#include <unistd.h>

static int my_strlen(const char *str)
{
    int len = 0;

    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);

    if (len1 != len2) {
        return 84;
    }
    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] != s2[i])
            return 84;
        i++;
    }
    return 0;
}
