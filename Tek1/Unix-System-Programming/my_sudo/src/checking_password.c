/*
** EPITECH PROJECT, 2025
** main
** File description:
** main for sudo
*/

#include "my.h"
#include "my_macro.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <crypt.h>

static int check_shadow_file(FILE *shadow_file)
{
    if (!shadow_file) {
        fprintf(stderr, "Error: Unable to open /etc/shadow.\n");
        return ERROR;
    }
    return 0;
}

static char *enter_your_password(void)
{
    char *my_password = getpass("Enter your password: ");

    if (!my_password) {
        fprintf(stderr, "Error: Failed to read password.\n");
        return NULL;
    }
    return my_password;
}

static char *hash_my_password(char *my_password, char *salt)
{
    char *my_password_hashed = crypt(my_password, salt);

    if (!my_password_hashed) {
        fprintf(stderr, "Error: Failed to hash\n");
    }
    return my_password_hashed;
}

static char *get_true_password_hashed(const char *username)
{
    FILE *shadow_file = fopen("/etc/shadow", "r");
    char line[256];
    char *hash = NULL;

    check_shadow_file(shadow_file);
    while (fgets(line, sizeof(line), shadow_file)) {
        if (strncmp(line, username,
            strlen(username)) == 0 && line[strlen(username)] == ':') {
            hash = strdup(strtok(line + strlen(username) + 1, ":"));
            break;
        }
    }
    fclose(shadow_file);
    return hash;
}

static int compare_passwords(char *my_password_hashed,
    char *true_hashed_password, int *attempts)
{
        if (strcmp(my_password_hashed, true_hashed_password) == 0) {
            printf("Successfull authentification \n");
            return SUCCESS;
        } else {
            printf("Password incorrect, attempts left: %d\n", *attempts - 1);
            (*attempts)--;
            return ERROR;
        }
        fprintf(stderr, "Error: Authentification failed\n");
        return ERROR;
}

static char *get_hashed_input_password(
    char *my_password, char *true_hashed_password)
{
    char *hashed = hash_my_password(my_password, true_hashed_password);

    if (!hashed) {
        fprintf(stderr, "Error: Failed to hash the input password\n");
        return NULL;
    }
    return hashed;
}

int handling_password_auth(const char *username)
{
    char *my_password = NULL;
    char *my_password_hashed = NULL;
    char *true_hashed_password = NULL;
    int attempts = 3;

    while (attempts > 0) {
        my_password = enter_your_password();
        if (!my_password)
        return ERROR;
        true_hashed_password = get_true_password_hashed(username);
        if (!true_hashed_password)
        return ERROR;
        my_password_hashed = get_hashed_input_password(my_password,
            true_hashed_password);
        if (compare_passwords(my_password_hashed,
            true_hashed_password, &attempts) == SUCCESS) {
            break;
        }
    }
    return SUCCESS;
}
