/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** write a function that counts and returns the number of char()
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
