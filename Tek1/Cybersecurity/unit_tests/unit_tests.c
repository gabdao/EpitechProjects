/*
** EPITECH PROJECT, 2024
** pipeto tests
** File description:
** pipeto tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OLD_BIN "../white_box/pipeto"
#define NEW_BIN "../recode/pipeto"

char *get_output(const char *bin_path, const char *command)
{
    char full_cmd[512];
    snprintf(full_cmd, sizeof(full_cmd), "echo \"%s\" | %s", command, bin_path);
    FILE *fp = popen(full_cmd, "r");
    if (!fp)
        return NULL;

    char *output = calloc(4096, sizeof(char));
    fread(output, 1, 4095, fp);
    pclose(fp);
    return output;
}

// void redirect_all_std(void)
// {
//     cr_redirect_stdout();
//     cr_redirect_stderr();
// }

Test(activate_emergency_protocols, no_password_test)
{
    char *old_output = get_output(OLD_BIN, "activate_emergency_protocols\n1234");
    char *new_output = get_output(NEW_BIN, "activate_emergency_protocols\n1234");

    cr_assert_str_eq(new_output, old_output, "activate_emergency_protocols not working anymore\n");
    fprintf(stderr, "Old:\n%s\n", old_output);
    fprintf(stderr, "New:\n%s\n", new_output);
    free(old_output);
    free(new_output);
}

// Test(activate_emergency_protocols, wrong_password)
// {
//     char *old_output = get_output(OLD_BIN, "activate_emergency_protocols\n1234\nquit");
//     char *new_output = get_output(NEW_BIN, "activate_emergency_protocols\n1234\nquit");

//     cr_assert_str_eq(new_output, old_output, "activate_emergency_protocols not working anymore\n");
//     fprintf(stderr, "Old:\n%s\n", old_output);
//     fprintf(stderr, "New:\n%s\n", new_output);
//     free(old_output);
//     free(new_output);
// }

// Test(activate_emergency_protocols, good_password)
// {
//     char *old_output = get_output(OLD_BIN, "activate_emergency_protocols\n1234\nquit");
//     char *new_output = get_output(NEW_BIN, "activate_emergency_protocols\n1234\nquit");

//     cr_assert_str_eq(new_output, old_output, "activate_emergency_protocols not working anymore\n");
//     fprintf(stderr, "Old:\n%s\n", old_output);
//     fprintf(stderr, "New:\n%s\n", new_output);
//     free(old_output);
//     free(new_output);
// }

// Test(check_cooling_pressure, test, .init = redirect_all_std)
// {
//     //non corrected program
//     //corrected program
// }

// Test(check_reactor_status, test, .init = redirect_all_std)
// {
//     //non corrected program
//     //corrected program
// }

// Test(configure_cooling_system, test, .init = redirect_all_std)
// {
//     //non corrected program
//     //corrected program
// }

// Test(enable_remote_access, test, .init = redirect_all_std)
// {
//     //non corrected program
//     //corrected program
// }

// Test(help, test, .init = redirect_all_std)
// {
//     //non corrected program
//     //corrected program
// }

// Test(history, test, .init = redirect_all_std)
// {
//     //non corrected program
//     //corrected program
// }

// Test(init_reactor, test, .init = redirect_all_std)
// {
//     //non corrected program
//     //corrected program
// }

// Test(load_config, test, .init = redirect_all_std)
// {
//     //non corrected program
//     //corrected program
// }

// Test(load_fuel_rods, test, .init = redirect_all_std)
// {
//     //non corrected program
//     //corrected program
// }

// Test(log_system_events, test, .init = redirect_all_std)
// {
//     //non corrected program
//     //corrected program
// }

// Test(monitor_radiation_levels, test, .init = redirect_all_std)
// {
//     //non corrected program
//     //corrected program
// }

// Test(quit, test, .init = redirect_all_std)
// {
//     //non corrected program
//     //corrected program
// }

// Test(run_diagnostic, test, .init = redirect_all_std)
// {
//     //non corrected program
//     //corrected program
// }

// Test(send_status_report, test, .init = redirect_all_std)
// {
//     //non corrected program
//     //corrected program
// }

// Test(set_reactor_power, test, .init = redirect_all_std)
// {
//     //non corrected program
//     //corrected program
// }

// Test(simulate_meltdown, test, .init = redirect_all_std)
// {
//     //non corrected program
//     //corrected program
// }

// Test(trigger_emergency_shutdown, test, .init = redirect_all_std)
// {
//     //non corrected program
//     //corrected program
// }

// Test(unlock_secret_mode, test, .init = redirect_all_std)
// {
//     //non corrected program
//     //corrected program
// }
