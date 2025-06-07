/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** check_reactor_status
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

static void print_checking_step(const char *msg, int delay)
{
    printf("%s\n", msg);
    sleep(delay);
}

static void xor_encrypt(const char *input, char *output, const char *key)
{
    size_t key_len = strlen(key);

    for (size_t i = 0; input[i] != '\0'; i++) {
        output[i] = input[i] ^ key[i % key_len];
    }
    output[strlen(input)] = '\0';
}

static void print_encrypted_status(const char *msg)
{
    char encrypted[64] = {0};
    const char *key = "pipetomaispaspipetard";

    xor_encrypt(msg, encrypted, key);
    sleep(1);
    printf("Encrypted message: ");
    for (size_t i = 0; msg[i] != '\0'; i++)
        printf("%02X", (unsigned char)encrypted[i]);
    printf("\n\n");
}

void check_reactor_status(void)
{
    printf("Starting reactor status check...\n");
    print_checking_step("Checking core temperature...", 1);
    print_checking_step("Core temperature: Normal", 1);
    print_checking_step("Checking coolant flow rate...", 1);
    print_checking_step("Coolant flow rate: Stable", 1);
    print_checking_step("Checking radiation levels...", 2);
    print_checking_step("Radiation levels: Safe\n", 0);
    printf("Encrypting critical reactor data...\n");
    print_encrypted_status("ReactorStatusOK");
    printf("Reactor status: OK\n");
    printf("Reactor status check complete.\n\n");
}
