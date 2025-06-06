/*
** EPITECH PROJECT, 2024
** my_top data retrieving
** File description:
** retrieving some data
*/

#include "my.h"
#include "my_macro.h"
#include <ncurses.h>
#include <curses.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <utmp.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

int my_getloadavg(double loadavg[], int nelem)
{
    FILE *file;

    if (nelem <= 0) {
        return -1;
    }
    file = fopen("/proc/loadavg", "r");
    if (!file) {
        return -1;
    }
    for (int i = 0; i < nelem; i++) {
        if (fscanf(file, "%lf", &loadavg[i]) != 1) {
            fclose(file);
            return -1;
        }
    }
    fclose(file);
    return 0;
}

int my_get_up_time(double *uptime_seconds)
{
    FILE *file;

    file = fopen("/proc/uptime", "r");
    if (!file) {
        return -1;
    }
    if (fscanf(file, "%lf", uptime_seconds) != 1) {
        fclose(file);
        return -1;
    }
    fclose(file);
    return 0;
}

static FILE *create_stat_path(const char *entry_name, char *stat_path)
{
    FILE *stat_file;

    snprintf(stat_path, STAT_PATH_SIZE, "/proc/%s/stat", entry_name);
    stat_file = fopen(stat_path, "r");
    if (!stat_file) {
        return NULL;
    }
    return stat_file;
}

static int extract_data_in_proc_stat(
    FILE *stat_file,
    task_counters_t *counters
)
{
    char state;

    if (fscanf(stat_file, "%*d %*s %c", &state) != 1) {
        return -1;
    }
    switch (state) {
        case 'R':
        counters->running++;
        break;
        case 'S':
        counters->sleeping++;
        break;
        case 'T':
        counters->stopped++;
        break;
        case 'Z':
        counters->zombie++;
        break;
    }
    return 0;
}

static int check_files_in_proc(DIR *proc_dir, task_counters_t *counters)
{
    struct dirent *entry;
    char stat_path[STAT_PATH_SIZE];
    FILE *stat_file;
    char state;

    entry = readdir(proc_dir);
    while (entry != NULL) {
        if (!isdigit(entry->d_name[0])) {
            entry = readdir(proc_dir);
            continue;
        }
        stat_file = create_stat_path(entry->d_name, stat_path);
        extract_data_in_proc_stat(stat_file, counters);
        fclose(stat_file);
        entry = readdir(proc_dir);
    }
    return 0;
}

int get_task_count(task_counters_t *counters)
{
    DIR *proc_dir;

    proc_dir = opendir("/proc");
    if (!proc_dir) {
        return -1;
    }
    counters->running = 0;
    counters->sleeping = 0;
    counters->stopped = 0;
    counters->zombie = 0;
    check_files_in_proc(proc_dir, counters);
    closedir(proc_dir);
    return counters->running +
    counters->sleeping +
    counters->stopped +
    counters->zombie;
}
