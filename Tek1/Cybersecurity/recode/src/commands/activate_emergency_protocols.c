/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** activate_emergency_protocols
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <crypt.h>
#include "pipeto.h"

static void free_func(char *auth, char *input_hashed, char *auth_hashed)
{
    free(auth);
    free(input_hashed);
    free(auth_hashed);
    return;
}

static char *loop_env(FILE *fd)
{
    char line[256];
    const char *prefix = "ACTIVATE_EMERGENCY_PROTOCOL_PWD=";
    int len_prefix = strlen(prefix);
    char *value = NULL;

    while (fgets(line, sizeof(line), fd)) {
        if (strncmp(line, prefix, len_prefix) == 0) {
            value = line + len_prefix;
            value[strcspn(value, "\n")] = '\0';
            fclose(fd);
            return strdup(value);
        }
    }
    fclose(fd);
    fprintf(stderr, "ACTIVATE_EMERGENCY_PROTOCOL_PWD not found in .env.\n");
    return NULL;
}

static char *retrieve_env_password(void)
{
    FILE *fd = fopen(".env", "r");

    if (!fd) {
        fprintf(stderr, "Failed to open .env file.\n");
        return NULL;
    }
    return loop_env(fd);
}

static char *get_password_input(void)
{
    char buffer[100];

    printf("Enter emergency password: ");
    if (!fgets(buffer, sizeof(buffer), stdin)) {
        fprintf(stderr, "Error reading input.\n");
        return NULL;
    }
    buffer[strcspn(buffer, "\n")] = 0;
    if (strlen(buffer) == 0) {
        printf("No password entered, emergency protocols not activated.\n");
        return NULL;
    }
    return strdup(buffer);
}

void activate_emergency_protocols(void)
{
    char *input = NULL;
    char *input_hashed = NULL;
    char *auth = NULL;
    char *auth_hashed = NULL;

    input = get_password_input();
    auth = retrieve_env_password();
    if (!auth)
        return;
    input_hashed = strdup(crypt(input, HASH_SALT));
    auth_hashed = strdup(crypt(auth, HASH_SALT));
    if (strcmp(input_hashed, auth_hashed) == 0) {
        printf("{Emergency protocols activated, you are now admin !}\n");
        IS_ADMIN = true;
    } else {
        printf("Wrong password emergency protocol not triggered\n");
    }
    free_func(auth, input_hashed, auth_hashed);
    return;
}
