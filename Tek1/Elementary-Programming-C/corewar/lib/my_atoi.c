/*
** EPITECH PROJECT, 2025
** my_atoi
** File description:
** reproduce the behaviour of the function atoi that converts char* into int
*/

int my_atoi(char *str)
{
    int result = 0;
    int start = 0;

    for (int i = 0; str[i] == ' ' || str[i] == '\t'; i++);
    if (str[start] == '-') {
        start = 1;
    }
    for (int i = start; str[i] >= '0' && str[i] <= '9'; i++) {
        result = result * 10 + (str[i] - '0');
    }
    return result;
}
