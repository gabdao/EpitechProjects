/*
** EPITECH PROJECT, 2025
** fazzbizz
** File Description:
** fazzbizz
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int my_strlen(char *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        len++;
    }
    return len;
}

static int err(char *str)
{
    write(2, str, my_strlen(str));
    return 0;
}

static int check_args(int nb_1, int nb_2, int argc, char **argv)
{
    if (argc != 3) {
        err("Error: need 2 args\n");
        return 84;
    }
    if (nb_1 > nb_2) {
        err
        ("Error: the second parameter must be greater than the first one.\n");
        return 84;
    }
    return 0;
}

static int check_conditions(int nb_1)
{
    if (nb_1 % 10 == 0 && nb_1 % 9 == 0) {
        printf("FazzBizz\n");
        return 1;
    }
    if (nb_1 % 9 == 0) {
        printf("Bizz\n");
        return 1;
    }
    if (nb_1 % 10 == 0) {
        printf("Fazz\n");
        return 1;
    }
    printf("%d\n", nb_1);
    return 0;
}

static int fazzbizz(int nb_1, int nb_2)
{
    while (nb_1 <= nb_2) {
    check_conditions(nb_1);
    nb_1++;
    }
    return 0;
}

int main(int argc, char **argv)
{
    int nb_1;
    int nb_2;

    if (argc != 3) {
        err("Error: need 2 args");
        return 84;
    }
    nb_1 = atoi(argv[1]);
    nb_2 = atoi(argv[2]);
    if (check_args(nb_1, nb_2, argc, argv) == 84) {
        return 84;
    }
    fazzbizz(nb_1, nb_2);
    return 0;
}
