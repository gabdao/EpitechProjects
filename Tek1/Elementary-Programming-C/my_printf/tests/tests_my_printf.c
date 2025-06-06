/*
** EPITECH PROJECT, 2024
** myprintf_tests
** File description:
** Tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("Hello, world!");
    cr_assert_stdout_eq_str("Hello, world!");
}

Test(flag_c, character_low, .init = redirect_all_std)
{
    my_printf("Character: %c", 'a');
    cr_assert_stdout_eq_str("Character: a");
}

Test(flag_c, character_maj, .init = redirect_all_std)
{
    my_printf("Character: %c", 'A');
    cr_assert_stdout_eq_str("Character: A");
}

Test(flag_c, character_empty, .init = redirect_all_std)
{
    my_printf("Character: %c", ' ');
    cr_assert_stdout_eq_str("Character:  ");
}

Test(flag_c, character_chiffre, .init = redirect_all_std)
{
    my_printf("Character: %c", '9');
    cr_assert_stdout_eq_str("Character: 9");
}

Test(flag_c, char_hh, .init = redirect_all_std)
{
    my_printf("my_printf flag_c hh: %hhd\n", (signed char)'A');
    cr_assert_stdout_eq_str("my_printf flag_c hh: 65\n");
}

Test(flag_s, string, .init = redirect_all_std)
{
    my_printf("i am the test of the: %s", "flag_s");
    cr_assert_stdout_eq_str("i am the test of the: flag_s");
}

Test(flag_d, integer_d, .init = redirect_all_std)
{
    my_printf("Number: %d", 42);
    cr_assert_stdout_eq_str("Number: 42");
}

Test(flag_d, integer_max, .init = redirect_all_std)
{
    my_printf("Max int: %d", 2147483647);
    cr_assert_stdout_eq_str("Max int: 2147483647");
}

Test(flag_d, int_min, .init = redirect_all_std)
{
    my_printf("Min int: %d\n", -2147483648);
    cr_assert_stdout_eq_str("Min int: -2147483648\n");
}

Test(flag_d, int_hh, .init = redirect_all_std)
{
    my_printf("my_printf flag_d hh: %hhd\n", (signed char)42);
    cr_assert_stdout_eq_str("my_printf flag_d hh: 42\n");
}

Test(flag_d, int_h, .init = redirect_all_std)
{
    my_printf("my_printf flag_d h: %hd\n", (short int)32767);
    cr_assert_stdout_eq_str("my_printf flag_d h: 32767\n");
}

Test(flag_i, int_i, .init = redirect_all_std)
{
    my_printf("Number: %i", 43);
    cr_assert_stdout_eq_str("Number: 43");
}

Test(flag_i, int_max_i, .init = redirect_all_std)
{
    my_printf("Max int with: %i", 2147483647);
    cr_assert_stdout_eq_str("Max int with: 2147483647");
}

Test(flag_i, int_min_i, .init = redirect_all_std)
{
    my_printf("Min int with: %i\n", -2147483648);
    cr_assert_stdout_eq_str("Min int with: -2147483648\n");
}

Test(flag_i, int_hh, .init = redirect_all_std)
{
    my_printf("my_printf flag_i hh: %hhi\n", (signed char)-128);
    cr_assert_stdout_eq_str("my_printf flag_i hh: -128\n");
}

Test(flag_i, int_h, .init = redirect_all_std)
{
    my_printf("my_printf flag_i h: %hi\n", (short int)-32768);
    cr_assert_stdout_eq_str("my_printf flag_i h: -32768\n");
}

Test(flag_u, unsigned_int, .init = redirect_all_std)
{
    my_printf("Unsigned int: %u", 'a');
    cr_assert_stdout_eq_str("Unsigned int: 97");
}

Test(flag_u, unsigned_max, .init = redirect_all_std)
{
    my_printf("Max unsigned int: %u", 4294967295);
    cr_assert_stdout_eq_str("Max unsigned int: 4294967295");
}

Test(flag_u, unsigned_hh, .init = redirect_all_std)
{
    my_printf("my_printf flag_u hh: %hhu\n", (unsigned char)255);
    cr_assert_stdout_eq_str("my_printf flag_u hh: 255\n");
}

Test(flag_u, unsigned_h, .init = redirect_all_std)
{
    my_printf("my_printf flag_u h: %hu\n", (unsigned short)65535);
    cr_assert_stdout_eq_str("my_printf flag_u h: 65535\n");
}

Test(flag_o, unsigned_int_base8_octal, .init = redirect_all_std)
{
    my_printf("Unsigned int base 8: %o", 83);
    cr_assert_stdout_eq_str("Unsigned int base 8: 123");
}

Test(flag_o, octal_hh, .init = redirect_all_std)
{
    my_printf("my_printf flag_o hh: %hho\n", (unsigned char)100);
    cr_assert_stdout_eq_str("my_printf flag_o hh: 144\n");
}

Test(flag_o, octal_h, .init = redirect_all_std)
{
    my_printf("my_printf flag_o h: %ho\n", (unsigned short)300);
    cr_assert_stdout_eq_str("my_printf flag_o h: 454\n");
}

Test(flag_x, unsigned_int_base16_hexa_low, .init = redirect_all_std)
{
    my_printf("Unsigned int base 16 low: %x", 960);
    cr_assert_stdout_eq_str("Unsigned int base 16 low: 3c0");
}

Test(flag_x, hex_lower_hh, .init = redirect_all_std)
{
    my_printf("my_printf flag_x hh: %hhx\n", (unsigned char)240);
    cr_assert_stdout_eq_str("my_printf flag_x hh: f0\n");
}

Test(flag_x, hex_lower_h, .init = redirect_all_std)
{
    my_printf("my_printf flag_x h: %hx\n", (unsigned short)65535);
    cr_assert_stdout_eq_str("my_printf flag_x h: ffff\n");
}

Test(flag_X, unsigned_int_base16_hexa_maj, .init = redirect_all_std)
{
    my_printf("Unsigned int base 16 maj: %X", 960);
    cr_assert_stdout_eq_str("Unsigned int base 16 maj: 3C0");
}

Test(flag_prct, prct, .init = redirect_all_std)
{
    my_printf("prct is: %%");
    cr_assert_stdout_eq_str("prct is: %");
}
