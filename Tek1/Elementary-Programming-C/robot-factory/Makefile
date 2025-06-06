##
## EPITECH PROJECT, 2025
## First makefile
## File description:
## Makefile that create lib, make tests and run them
##

##Fonctions for mini_printf
CFILES	+=	./lib/mini_printf.c

## Fonctions de la piscine
CFILES +=	./lib/my_putchar.c				\
			./lib/my_put_nbr.c				\
			./lib/my_putstr.c				\
			./lib/my_strlen.c				\
			./lib/my_strcpy.c				\
			./lib/my_strcmp.c				\
			./lib/my_strncmp.c				\
			./lib/my_strcat.c				\
			./lib/my_strdup.c 				\
			./lib/my_str_to_word_array.c	\
            ./lib/my_strncpy.c				\
			./lib/free_array.c

##FONCTION DU PROJETS
SRC      =	./src/main.c							\
			./src/parsing/handler_file_parsing.c	\
			./src/writing/writer.c					\
			./src/body/writing/body_writing.c		\
			./src/utils/utils.c						\
			./src/op.c								\
			./src/body/handling_body.c				\
			./src/body/check_conditions_body.c		\
			./src/body/handle_linked_list.c       	\
			./src/utils/header_error.c				\
			./src/body/print_body_data.c			\
			./src/body/writing/opcode.c             \
			./src/body/writing/params.c             \
			./src/utils/little_to_big_endian.c		\
			./src/utils/champion_file_size.c

CFLAGS	+=	-iquote ./include

LDFLAGS	+=	-L.

LDLIBS	=	-lmy

OFILES	=	$(CFILES:.c=.o)

LIBNAME	=	libmy.a
BINARY_NAME =	asm

all:    $(LIBNAME) $(BINARY_NAME) clean

$(LIBNAME):	$(OFILES)
	ar rc $(LIBNAME) $(OFILES)

$(BINARY_NAME): $(LIBNAME)
	gcc -o $(BINARY_NAME) $(SRC) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(LIBNAME) $(BINARY_NAME) unit_tests

re: fclean all
	rm -f $(OFILES)
##Ne pas oublier de changer les tests
unit_tests: fclean $(LIBNAME)
	gcc -o unit_tests tests/tests_mini_printf.c mini_printf.c \
	-Include/my.h -L./ -lmy -lcriterion --coverage
tests_run: unit_tests
	./unit_tests
