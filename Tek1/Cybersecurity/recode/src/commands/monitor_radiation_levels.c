/*
** EPITECH PROJECT, 2024
** Pipeto
** File description:
** monitor_radiation_levels
*/

#include <stdio.h>
#include <string.h>

void monitor_radiation_levels(void)
{
    char buffer[10];

    printf("Enter radiation levels: ");
    fgets(buffer, sizeof(buffer), stdin);
    printf("Radiation Levels: %s\n", buffer);
}
