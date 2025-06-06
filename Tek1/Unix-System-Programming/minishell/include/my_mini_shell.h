/*
** EPITECH PROJECT, 2025
** my mini shell header
** File description:
** min shell macros
*/

#ifndef _MY_MSH2_H_
    #define _MY_MSH2_H_

// Core shell functions
int shell_loop(char **env);

// Data creation functions
char **read_stdin_and_convert_input_to_new_argv(char **new_argv);
int counting_new_argc(char **new_argv);
char **copy_env_to_new_env(char **env, char **new_env);

// Path handling functions
char *get_path_from_new_env(char **env);
char *find_command_in_path(char *path, char *command);

//Parsing for special commands ; | < etc...
typedef struct separator_flags_s {
    int separator;
    int pipe;
    int redirection;
    int special_command;
} separator_flags_t;

int dispatch_command(char **new_argv, char ***new_env, int new_argc);
int parse_and_execute(char **argv, char ***env, separator_flags_t flags);
int handle_multiple_commands(char **argv, char ***env);
int handle_pipe_command(char **argv, char ***env);
int handle_redirection(char **argv, char ***env);

// Command handling functions
int check_new_argv(char **new_argv, char ***new_env, int new_argc);
int handle_extern_commands(char **new_argv, char **new_env);

// Handle builtins functions
struct builtins_and_functions {
    char *builtins;
    int (*function_ptr)(char **new_argv, char ***new_env, int new_argc);
};

int handle_cd(char **new_argv, char ***new_env, int new_argc);
int handle_setenv(char **new_argv, char ***new_env, int new_argc);
int handle_unsetenv(char **new_argv, char ***new_env, int new_argc);
int handle_env(char **new_argv, char ***new_env, int new_argc);
int handle_exit(char **new_argv, char ***new_env, int new_argc);

// Error handling functions
void check_file_exists(char *executable);
void check_file_executable(char *executable);
void check_is_directory(char *executable);
void check_binary_compatible(char *executable);
int handle_signal_error(int signal);

//Utils functions
int is_valid_env_name(char *name);
char **strdup_array(char **argv, int start, int end);

#endif /* _MY_MSH2_H_ */
