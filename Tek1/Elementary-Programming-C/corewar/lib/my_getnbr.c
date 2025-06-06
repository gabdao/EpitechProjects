/*
** EPITECH PROJECT, 2025
** getnbr
** File description:
** my_getnbr.c
*/

int my_getnbr(const char *str)
{
    int result = 0;
    int sign = 1;

    while (*str == '-' || *str == '+') {
        if (*str == '-') {
            sign *= -1;
        }
        str++;
    }
    while (*str != '\0' && *str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }
    result *= sign;
    return result;
}
