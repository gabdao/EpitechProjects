/*
** EPITECH PROJECT, 2025
** main
** File description:
** main for sudo
*/

#include "my.h"
#include "my_macro.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const struct flags_and_functions table[] = {
    {'h', handle_help},
    {'u', handle_user},
    {'g', handle_group},
    {'s', handle_shell},
    {'i', handle_login_shell},
    {'b', handle_background},
    {'l', handle_list},
    {'v', handle_validate},
    {'k', handle_invalidate_cache},
    {'E', handle_preserve_env}
};

int handling_flags(void)
{
    return SUCCESS;
}
