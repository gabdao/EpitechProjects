/*
** EPITECH PROJECT, 2025
** error_handling
** File description:
** file to handle all error checks
*/

#include "my.h"
#include "my_mini_shell.h"
#include "my_macro.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>

void check_file_exists(char *executable)
{
    if (access(executable, F_OK) != SUCCESS) {
        write(2, executable, my_strlen(executable));
        write(2, ": Command not found.\n", 21);
        exit(1);
    }
}

void check_file_executable(char *executable)
{
    if (access(executable, X_OK) != SUCCESS) {
        write(2, executable, my_strlen(executable));
        write(2, ": Permission denied.\n", 20);
        exit(1);
    }
}

void check_is_directory(char *executable)
{
    struct stat st;

    if (stat(executable, &st) == 0 && S_ISDIR(st.st_mode)) {
        write(2, executable, my_strlen(executable));
        write(2, ": Is a directory.\n", 17);
        exit(1);
    }
}

void check_binary_compatible(char *executable)
{
    write(2, executable, my_strlen(executable));
    write(2, ": Exec format error. Binary not compatible.\n", 42);
    exit(1);
}

int handle_signal_error(int signal)
{
    if (signal == SIGSEGV) {
        write(2, "Segmentation fault (core dumped)\n", 32);
        return SEGFAULT;
    }
    if (signal == SIGFPE) {
        write(2, "Floating point exception\n", 24);
        return 136;
    }
    if (signal == SIGABRT) {
        write(2, "Aborted (core dumped)\n", 22);
        return 134;
    }
    return 128 + signal;
}
