/*
** EPITECH PROJECT, 2025
** unit_tests
** File description:
** testing builtins
*/

#include <criterion/criterion.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "unit_tests.h"

// test(builtins, test_handle_cd_root)
// {
//     char *args[] = {"cd", "/", NULL};
//     char *env[] = {NULL};
//     int ret = handle_cd(args, env, 2);
//     char cwd[1024];
//     getcwd(cwd, sizeof(cwd));
//     cr_assert_eq(ret, 0, "handle_cd should return 0 on success");
//     cr_assert_str_eq(cwd, "/", "Should be in root directory after cd /");
// }

// test(builtins, test_handle_exit_returns_code)
// {
//     char *args[] = {"exit", "42", NULL};
//     char *env[] = {NULL};
//     int ret = handle_exit(args, env, 2);
//     cr_assert_eq(ret, 42, "handle_exit should return the exit code");
// }
