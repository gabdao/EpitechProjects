/*
** EPITECH PROJECT, 2025
** Pipeto
** File description:
** history
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "history.h"

static char **history = NULL;
static int history_count = 0;
static int history_size = 0;

static history_init_loop(char *line)
{
    if (strlen(line) > 0) {
        history[history_count] = strdup(line);
        if (history[history_count])
            history_count++;
    }
}

void history_init(void)
{
    FILE *file;
    char line[MAX_COMMAND_LENGTH];

    history = malloc(sizeof(char *) * MAX_HISTORY_SIZE);
    if (!history)
        return;
    history_size = MAX_HISTORY_SIZE;
    history_count = 0;
    file = fopen(HISTORY_FILE, "r");
    if (file) {
        while (fgets(line, sizeof(line), file) && history_count <
        MAX_HISTORY_SIZE) {
            line[strcspn(line, "\n")] = '\0';
            history_init_loop(line);
        }
        fclose(file);
    }
}

static history_add_fd(void)
{
    FILE *file;

    file = fopen(HISTORY_FILE, "w");
    if (file) {
        for (int i = 0; i < history_count; i++)
            fprintf(file, "%s\n", history[i]);
        fclose(file);
    }
}

void history_add(const char *command)
{
    if (!command || strlen(command) == 0 ||
        (history_count > 0 && strcmp(history[history_count - 1],
            command) == 0))
        return;
    if (history_count == history_size) {
        free(history[0]);
        for (int i = 0; i < history_count - 1; i++)
            history[i] = history[i + 1];
        history_count--;
    }
    history[history_count] = strdup(command);
    if (history[history_count])
        history_count++;
    history_add_fd();
}

void history_clear(void)
{
    FILE *file;

    for (int i = 0; i < history_count; i++)
        free(history[i]);
    history_count = 0;
    file = fopen(HISTORY_FILE, "w");
    if (file)
        fclose(file);
}

void history_free(void)
{
    for (int i = 0; i < history_count; i++)
        free(history[i]);
    free(history);
    history = NULL;
    history_count = 0;
    history_size = 0;
}

void history_show(void)
{
    for (int i = 0; i < history_count; i++)
        printf(" %d  %s\n", i + 1, history[i]);
}

const char *history_get(int index)
{
    if (index < 0 || index >= history_count)
        return NULL;
    return history[index];
}

int history_count_get(void)
{
    return history_count;
}
