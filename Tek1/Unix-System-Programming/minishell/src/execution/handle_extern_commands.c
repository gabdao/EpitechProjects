/*
** EPITECH PROJECT, 2025
** handle_extern_commands
** File description:
** file to handle external commands
*/

#include "my.h"
#include "my_mini_shell.h"
#include "my_macro.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>

static void handle_child_process(
    char *executable, char **new_argv, char **new_env)
{
    check_file_exists(executable);
    check_file_executable(executable);
    check_is_directory(executable);
    execve(executable, new_argv, new_env);
    check_binary_compatible(executable);
}

static int handle_parent_process(pid_t pid)
{
    int status = 0;
    int exit_code = 0;
    int signal = 0;

    waitpid(pid, &status, 0);
    if (WIFEXITED(status)) {
        exit_code = WEXITSTATUS(status);
        return exit_code;
    } else if (WIFSIGNALED(status)) {
        signal = WTERMSIG(status);
        return handle_signal_error(signal);
    }
    return SUCCESS;
}

static int exec_command(char *executable, char **new_argv, char **new_env)
{
    pid_t pid = fork();

    if (pid == 0) {
        handle_child_process(executable, new_argv, new_env);
    } else if (pid > 0) {
        return handle_parent_process(pid);
    }
    return SUCCESS;
}

static int is_direct_path(char *command)
{
    if (my_strncmp(command, "./", 2) == SUCCESS) {
        return FOUND;
    }
    if (command[0] == '/') {
        return FOUND;
    }
    return NOT_FOUND;
}

int handle_extern_commands(char **new_argv, char **new_env)
{
    char *path_env = NULL;
    char *command_path = NULL;
    int return_value = SUCCESS;

    if (is_direct_path(new_argv[0]) == FOUND) {
        return exec_command(new_argv[0], new_argv, new_env);
    }
    path_env = get_path_from_new_env(new_env);
    command_path = find_command_in_path(path_env, new_argv[0]);
    if (command_path) {
        return_value = exec_command(command_path, new_argv, new_env);
        free(command_path);
        return return_value;
    }
    write(2, new_argv[0], my_strlen(new_argv[0]));
    write(2, ": Command not found.\n", 21);
    return ERROR_CMD;
}
