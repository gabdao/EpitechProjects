/*
** EPITECH PROJECT, 2024
** my_strncmp
** File description:
** Function that compares 2 strings to know if one is bigger
*/

int my_strncmp(const char *s1, const char *s2, int n)
{
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0') {
            return s1[i] - s2[i];
        }
    }
    return 0;
}
