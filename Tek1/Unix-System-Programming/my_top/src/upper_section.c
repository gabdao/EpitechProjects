/*
** EPITECH PROJECT, 2024
** my_top upper section display
** File description:
** displaying upper section
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
#include <time.h>

void display_loadavg(int delay_ms)
{
    double loadavg[3];

    if (my_getloadavg(loadavg, 3) != 0) {
        printw("load average: ERROR");
        return;
    }
    printw("load average: %.2f, %.2f, %.2f",
        loadavg[0], loadavg[1], loadavg[2]);
}

void display_time(void)
{
    time_t raw_time;
    struct tm *time_info;

    time(&raw_time);
    time_info = localtime(&raw_time);
    printw("top - %02d:%02d:%02d ",
            time_info->tm_hour, time_info->tm_min, time_info->tm_sec);
}

static void calculate_time_units(double uptime,
    int *days, int *hours, int *minutes)
{
    *days = uptime / 86400;
    uptime -= *days * 86400;
    *hours = uptime / 3600;
    uptime -= *hours * 3600;
    *minutes = uptime / 60;
}

void display_uptime(void)
{
    double uptime_seconds;
    int days;
    int hours;
    int minutes;

    if (my_get_up_time(&uptime_seconds) != 0) {
        printw("up ERROR");
        return;
    }
    calculate_time_units(uptime_seconds, &days, &hours, &minutes);
    printw("up ");
    if (days > 0)
        printw("%d day%s, ", days, (days > 1) ? "s" : "");
    if (hours > 0 || days > 0) {
        printw("%2d:%02d", hours, minutes);
    } else {
        printw("%d min", minutes);
    }
}

void display_task_count(void)
{
    int total;
    task_counters_t counters;

    total = get_task_count(&counters);
    printw(
    "Tasks:  %4d total,   %3d running,  %3d sleeping,   "
    "%3d stopped,   %3d zombie\n",
    total,
    counters.running,
    counters.sleeping,
    counters.stopped,
    counters.zombie
    );
}
