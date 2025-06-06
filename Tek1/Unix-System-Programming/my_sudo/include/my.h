/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my.h
*/

#include <stdarg.h>
#ifndef MY_H
    #define MY_H

typedef struct env_info {
    char *user;
    char *shell;
    char *home;
} env_info_t;

env_info_t *get_env_info(char **env);

struct flags_and_functions {
    char flags;
    int (*function_ptr)(const char *format, int *i, va_list args);
};
int handle_sudoers(const char *username);
int handle_help(void);
int handle_user(void);
int handle_group(void);
int handle_shell(void);
int handle_login_shell(void);
int handle_background(void);
int handle_list(void);
int handle_validate(void);
int handle_invalidate_cache(void);
int handle_preserve_env(void);
int handling_password_auth(const char *username);
int my_exec(char **av);

#endif
