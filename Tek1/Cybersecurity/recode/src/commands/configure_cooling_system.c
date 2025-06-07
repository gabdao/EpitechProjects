/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** configure_cooling_system
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

static int check_cmd(char *cmd)
{
    const char *ban_cmd[] = {"sudo", "rm", "rm -rf", ":(){ :|:& };:", NULL};

    for (size_t i = 0; ban_cmd[i] != NULL; ++i) {
        if (strcmp(cmd, ban_cmd[i]) == 0) {
            fprintf(stderr, "Error: Banned command: %s\n", cmd);
            return -1;
        }
    }
    return 0;
}

static char *build_path(char *cmd)
{
    const char *base = "/bin/";
    size_t len = strlen(base) + strlen(cmd) + 1;
    char *full_path = malloc(len);

    if (!full_path)
        return NULL;
    strcpy(full_path, base);
    strcat(full_path, cmd);
    return full_path;
}

static int exec_buffer(char *buffer)
{
    char *token = strtok(buffer, " ");
    char *path = NULL;

    while (token != NULL) {
        if (check_cmd(token) == -1)
            return -1;
        path = build_path(token);
        if (!path) {
            fprintf(stderr, "Could not allocate memory for command path\n");
            return -1;
        }
        execl(path, token, NULL);
        perror("execl failed");
        free(path);
        token = strtok(NULL, " ");
    }
    return 0;
}

static void handle_cooling_config(char *buffer)
{
    int result = 0;

    printf("Applying configuration: %s\n", buffer);
    result = exec_buffer(buffer);
    if (result != -1) {
        printf("Configuration applied successfully.\n");
    } else {
        printf("Failed to apply configuration. Command returned:%d\n", result);
    }
    return;
}

void configure_cooling_system(void)
{
    char *config_file = "./Data/cooling_config.txt";
    char buffer[64];
    FILE *file = fopen(config_file, "r");

    if (!file) {
        fprintf(stderr, "Error: NO file found %s\n", config_file);
        return;
    }
    printf("Reading configuration file: %s\n", config_file);
    fread(buffer, 1, sizeof(buffer) - 1, file);
    buffer[sizeof(buffer) - 1] = '\0';
    fclose(file);
    handle_cooling_config(buffer);
}
