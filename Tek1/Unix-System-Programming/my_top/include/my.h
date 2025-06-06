/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** header for mylib
*/
#include <stdarg.h>
#include <dirent.h>
#include <stdio.h>
#ifndef MY_H
    #define MY_H

//Struct to handle tasks
typedef struct {
    int running;
    int sleeping;
    int stopped;
    int zombie;
} task_counters_t;

//Functions to display
void display_loadavg(int delay_ms);
void display_time(void);
void display_uptime(void);
void display_user_count(void);
void display_task_count(void);

//Functions to retrieve data
int my_getloadavg(double loadavg[], int nelem);
int my_get_up_time(double *uptime_seconds);
int get_user_count(void);
int get_task_count(task_counters_t *counters);
static int check_files_in_proc(DIR *proc_dir, task_counters_t *counters);
static int extract_data_in_proc_stat(
    FILE *stat_file,
    task_counters_t *counters
);
#endif
