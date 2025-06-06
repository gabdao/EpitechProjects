##
## EPITECH PROJECT, 2025
## Makefile for minishell2
## File description:
## minishell2 with tests
##

CC = gcc
CFLAGS = -g3
INCLUDES = -Iinclude
LDFLAGS = -L. -lmy -lcriterion

VALGRIND = valgrind
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes

## Lib perso
CFILES = \
	lib/my/my_printf.c \
	lib/my/handle_g.c \
	lib/my/my_put_unsigned_nbr.c \
	lib/my/my_putfloat.c \
	lib/my/handle_c.c \
	lib/my/handle_d_i.c \
	lib/my/handle_e.c \
	lib/my/my_put_e.c \
	lib/my/my_put_up_e.c \
	lib/my/handle_up_e.c \
	lib/my/handle_f.c \
	lib/my/handle_up_f.c \
	lib/my/handle_g_and_upcase_g.c \
	lib/my/handle_n.c \
	lib/my/handle_o.c \
	lib/my/handle_p.c \
	lib/my/handle_prct.c \
	lib/my/handle_s.c \
	lib/my/handle_u.c \
	lib/my/handle_x.c \
	lib/my/handle_upcase_x.c \
	lib/my/my_putchar.c \
	lib/my/my_isneg.c \
	lib/my/my_put_nbr.c \
	lib/my/my_swap.c \
	lib/my/my_putstr.c \
	lib/my/my_strlen.c \
	lib/my/my_getnbr.c \
	lib/my/my_sort_int_array.c \
	lib/my/my_compute_power_rec.c \
	lib/my/my_compute_square_root.c \
	lib/my/my_is_prime.c \
	lib/my/my_find_prime_sup.c \
	lib/my/my_strcpy.c \
	lib/my/my_strncpy.c \
	lib/my/my_revstr.c \
	lib/my/my_strcmp.c \
	lib/my/my_strncmp.c \
	lib/my/my_strupcase.c \
	lib/my/my_strlowcase.c \
	lib/my/my_strcapitalize.c \
	lib/my/my_str_isalpha.c \
	lib/my/my_str_isnum.c \
	lib/my/my_str_islower.c \
	lib/my/my_str_isupper.c \
	lib/my/my_str_isprintable.c \
	lib/my/my_showstr.c \
	lib/my/my_showmem.c \
	lib/my/my_strcat.c \
	lib/my/my_strncat.c \
	lib/my/my_strdup.c \
	lib/my/my_str_to_word_array.c \
	lib/my/my_free_array.c

## SRC
MAIN = src/core/main.c

CORE = \
	src/core/shell_loop.c	\
	src/core/dispatcher.c

INPUT = \
	src/input/handle_new_argv.c \
	src/input/create_data_in_shell.c

PARSING = \
	src/parsing/handle_multiple_commands.c \
	src/parsing/handle_pipe_command.c	\
	src/parsing/handle_redirection.c	\
	src/parsing/parse_and_execute.c


EXEC = \
	src/execution/handle_extern_commands.c \
	src/execution/path_handling.c

UTILS = \
	src/utils/error_handling.c	\
	src/utils/check_name_env.c	\
	src/utils/strdup_array.c

BUILTINS = \
	src/builtins/cd.c \
	src/builtins/setenv.c \
	src/builtins/unsetenv.c \
	src/builtins/env.c \
	src/builtins/exit.c

SRC = $(MAIN) $(CORE) $(INPUT) $(EXEC) $(UTILS) $(BUILTINS) $(PARSING)

NO_MAIN = $(CORE) $(INPUT) $(EXEC) $(UTILS) $(BUILTINS)

TESTS = \
	unit_test/test_builtins.c

TEST_BIN = unit_tests

OFILES = $(CFILES:.c=.o)
LIBNAME = libmy.a
BINARY_NAME = mysh


all: $(LIBNAME) $(BINARY_NAME) clean

$(LIBNAME): $(OFILES)
	ar rc $(LIBNAME) $(OFILES)

$(BINARY_NAME): $(LIBNAME)
	$(CC) $(CFLAGS) -o $(BINARY_NAME) $(SRC) $(INCLUDES) $(LDFLAGS)

valgrind: $(BINARY_NAME)
	$(VALGRIND) $(VALGRIND_FLAGS) ./$(BINARY_NAME)

debug: CFLAGS += -g3
debug: re

$(TEST_BIN): $(LIBNAME)
	$(CC) $(CFLAGS) $(NO_MAIN) $(TESTS) -o $(TEST_BIN) $(INCLUDES) $(LDFLAGS)

tests_run: $(UNIT_TEST_BINARY)
	./$(UNIT_TEST_BINARY)

clean:
	rm -f $(OFILES)
	rm -f *.gcda *.gcno unit_tests-*.gcda unit_tests-*.gcno

fclean: clean
	rm -f $(LIBNAME) $(BINARY_NAME) $(UNIT_TEST_BINARY)

re: fclean all

.PHONY: all clean fclean re valgrind debug tests_run
