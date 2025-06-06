/*
** EPITECH PROJECT, 2024
** my_top
** File description:
** my_top
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

int handle_delay(int delay, int key_inserted)
{
    if (key_inserted == '+') {
        delay += 100000;
        if (delay > 5000000) {
            delay = 5000000;
        }
    }
    if (key_inserted == '-') {
        delay -= 100000;
        if (delay < 100000) {
            delay = 100000;
        }
    }
    return delay;
}

void handle_window(int init)
{
    if (init) {
        initscr();
        noecho();
        curs_set(0);
    } else {
        endwin();
    }
}

static int display_upper_section(int delay)
{
    display_time();
    display_uptime();
    display_loadavg(delay);
    display_task_count();
    return 0;
}

static int loop(int *counter, int delay)
{
    int key_inserted;

    while (1) {
        key_inserted = getch();
        if (key_inserted == 'Q' || key_inserted == 'q') {
            return 1;
        }
        if (*counter >= delay) {
            clear();
            display_upper_section(delay);
            refresh();
            *counter = 0;
        }
        (*counter)++;
    }
    return 0;
}

int main(void)
{
    int delay = 3000;
    int counter = 0;

    handle_window(START_WINDOW);
    clear();
    display_upper_section(delay);
    refresh();
    timeout(1);
    loop(&counter, delay);
    handle_window(STOP_WINDOW);
    return 0;
}
