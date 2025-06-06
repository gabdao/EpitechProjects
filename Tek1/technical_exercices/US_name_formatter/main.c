/*
** EPITECH PROJECT, 2025
** mainc.c
** File Description:
** us formatter name
*/

#include <unistd.h>
#include <stdio.h>

static int my_putchar(char c)
{
    write(1, &c, 1);
    return 0;
}

int handle_first_name(char *str, int i)
{
    printf("test\n");
    my_putchar(str[0]);
    return 0;
}

static int handle_last_name(char *str, int last_name)
{
    if (str[last_name] >= 'a' && str[last_name] <= 'z') {
        my_putchar(str[last_name] - 32);
    }
    if (str[last_name] >= 'A' && str[last_name] <= 'Z') {
        my_putchar (str[last_name]);
    }
    for (str[last_name + 1]; str[last_name + 1] != '\0'; last_name++) {
        if (str[last_name + 1] >= 'A' && str[last_name + 1] <= 'Z') {
            my_putchar(str[last_name + 1] + 32);
            continue;
        }
        my_putchar(str[last_name + 1]);
    }
    return 0;
}

static int count_firstname(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != ' '; i++) {
        count++;
    }
    return count;
}

static int check_conditions(char *str)
{
    int len_first_name = count_firstname(str);
    int last_name = len_first_name + 1;
    
    printf("aya");
    for (int i = 0; str[i] < len_first_name; i++) {
        printf("test");
        handle_first_name(str, i);
    }
    printf("yyyy");
    my_putchar(' ');
    handle_last_name(str, last_name);
    return 0;
}

int main(int argc, char **argv)
{
    char *full_name = NULL;

    if (argc < 2) {
        return 84;
    }
    full_name = argv[1];
    check_conditions(full_name);
    return 0;
}
