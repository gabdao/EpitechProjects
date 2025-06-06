/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** Function that compares two strings charcaters by character
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0') {
        i++;
    }
    return s1[i] - s2[i];
}
