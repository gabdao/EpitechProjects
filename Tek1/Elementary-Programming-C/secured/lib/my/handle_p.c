/*
** EPITECH PROJECT, 2024
** myprintf
** File description:
** Handle p
*/

#include "../../include/my.h"
#include <stdio.h>
int cut_ptr_number(unsigned long long int nb)
{
    if (nb < 16) {
        if (nb < 10)
            my_putchar(nb + '0');
        else
            my_putchar(nb - 10 + 'a');
        return 0;
    }
    cut_ptr_number(nb / 16);
    if (nb % 16 < 10)
        my_putchar((nb % 16) + 48);
    else
        my_putchar((nb % 16) - 10 + 'a');
    return 0;
}

int handle_p(const char *format, int *i, va_list args)
{
    void *ptr = va_arg(args, void *);

    my_putchar('0');
    my_putchar('x');
    cut_ptr_number((unsigned long long int)ptr);
    return 0;
}
