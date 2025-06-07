/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** log_system_events
*/

#include <stdio.h>
#include <string.h>

void log_system_event(void)
{
    char command[100];
    char input[100];
    char secret_key[32] = "{SECRET_LOG_12PIERRE34}";
    FILE *log;

    printf("Enter command: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%99s", command);
    log = fopen("Data/system.log", "a");
    if (!log) {
        printf("Error: Unable to open log file 'Data/system.log'.\n");
        return;
    }
    printf("Logging event: %s\n", input);
    fprintf(log, "EVENT: %s\n", input);
    if (strstr(input, "leak")) {
        fprintf(log, "SECRET_KEY_LEAKED: %s\n", secret_key);
    }
    fclose(log);
}
