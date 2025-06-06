/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** header for mylib
*/
#include <stdarg.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#ifndef MY_HANDLING_SCRIPT_FILES_H_
    #define MY_HANDLING_SCRIPT_FILES_H_

typedef struct {
    int x_start;
    int y_start;
    int x_end;
    int y_end;
    int speed;
    int delay;
} plane_t;

typedef struct {
    int x;
    int y;
    int radius;
} tower_t;

int handling_script_files(int argc, char **argv);
char *read_file_to_string(FILE *file);
#endif /* MY_HANDLING_SCRIPT_FILES_H_ */
