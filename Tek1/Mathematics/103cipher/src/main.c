/*
** EPITECH PROJECT, 2024
** 103cipher
** File description:
** 103cipher
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include "my.h"
#include "my_macro.h"

int error_handling(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        return 0;
    }
    if (argc != 4) {
        fprintf(stderr, "Error: Invalid number of arguments\n");
        return 84;
    }
    if (argv[3][0] != '0' && argv[3][0] != '1') {
        fprintf(stderr, "Error: Invalid flag (expected '0' or '1')\n");
        return 84;
    }
    return 0;
}

static int crypt_message(char *message, int **key_matrice)
{
    printf("In crypt");
    return 0;
}

static int decrypt_message(char *message, int **key_matrice)
{
    printf("In decrypt");
    return 0;
}

void print_usage(void)
{
    printf("USAGE\n");
    printf("./103cipher message key flag\n\n");
    printf("DESCRIPTION\n");
    printf("message   a message, made of ASCII characters\n");
    printf("key       the encryption key, made of ASCII characters\n");
    printf("flag      0 for the message to be encrypted, 1 to be decrypted\n");
}

int main(int argc, char **argv)
{
    char *message;
    char *key;
    int **key_matrice;

    if (error_handling(argc, argv) == 84) {
    return 84;
    }
    if (argv[1][0] == '-' && argv[1][1] == 'h') {
        print_usage();
        return 0;
    }
    message = argv[1];
    key = argv[2];
    key_matrice = key_to_matrice(key);
    if (argv[3][0] == '0') {
        crypt_message(message, key_matrice);
    } else if (argv[3][0] == '1') {
        decrypt_message(message, key_matrice);
    }
    return 0;
}
