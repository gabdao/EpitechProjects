##
## EPITECH PROJECT, 2025
## First makefile
## File description:
## Makefile that create lib, make tests and run them
##

##FONCTION DU PROJETS
SRC      =	$(addprefix src/,				\
			main.c							\
			handle_game.c					\
			op.c							\
			game/init_processes.c			\
			game/loop_game.c				\
			game/dump_memory.c              \
			game/cycle_to_die.c             \
			game/main_features.c            \
			game/display_winner.c			\
			args/read_args.c				\
			args/handle_default.c           \
			parsing/open_champ_file.c		\
			utils/is_cor_file.c 			\
			utils/little_to_big_endian.c	\
			utils/has_coding_byte.c         \
			utils/get_arg_type.c            \
			game/instructions/add.c         \
			game/instructions/aff.c         \
			game/instructions/and.c         \
			game/instructions/fork.c        \
			game/instructions/ld.c          \
			game/instructions/ldi.c         \
			game/instructions/lfork.c       \
			game/instructions/live.c        \
			game/instructions/lld.c         \
			game/instructions/lldi.c        \
			game/instructions/or.c          \
			game/instructions/st.c          \
			game/instructions/sti.c         \
			game/instructions/sub.c         \
			game/instructions/xor.c         \
			game/instructions/zjmp.c        \
			)

CFLAGS	+=	-iquote ./include -Wextra -Wall

LDFLAGS	+=	-Llib

LDLIBS	=	-lmy

OBJ	=	$(SRC:.c=.o)

LIBNAME	=	libmy.a
BINARY_NAME =	corewar

all:	$(BINARY_NAME)

$(BINARY_NAME):	$(OBJ)
	make -C ./lib
	$(CC) -o $(BINARY_NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

debug: CPPFLAGS += -pedantic -g3 -ggdb3
debug:	$(OBJ)
	make -C ./lib
	$(CC) -o $(BINARY_NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

clean:
	make clean -C ./lib
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./lib
	rm -f $(LIBNAME) $(BINARY_NAME) unit_tests $(OBJ)

re: fclean all
	rm -f $(OBJ)
##Ne pas oublier de changer les tests
unit_tests: fclean $(LIBNAME)
	gcc -o unit_tests tests/tests_mini_printf.c mini_printf.c \
	-Include/my.h -L./ -lmy -lcriterion --coverage
tests_run: unit_tests
	./unit_tests

.PHONY:		all clean fclean re debug
