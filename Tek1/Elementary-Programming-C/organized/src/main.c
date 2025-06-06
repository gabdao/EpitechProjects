/*
** EPITECH PROJECT, 2024
** Organized
** File description:
** Projet Organized
*/

#include "my.h"
#include "shell.h"
#include "my_macro.h"
#include "materials.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    workshop_t workshop;

    workshop.head = NULL;
    workshop.next_id = 0;
    workshop_shell(&workshop);
    return 0;
}
