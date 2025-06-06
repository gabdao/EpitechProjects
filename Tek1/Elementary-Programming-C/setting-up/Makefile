##
## EPITECH PROJECT, 2024
## First makefile
## File description:
## Makefile that create lib, make tests and run them
##

CFLAGS = -Iinclude

##Fonctions for setting_up
CFILES	= 	./src/algo_setting_up.c	\
			./src/errors_handler_su.c	\
			./src/main.c
##Fonctions for my_printf
CFILES	+=	./lib/my/my_printf.c	\
			./lib/my/handle_g.c	\
			./lib/my/my_put_unsigned_nbr.c	\
			./lib/my/my_putfloat.c	\
			./lib/my/handle_c.c	\
			./lib/my/handle_d_i.c	\
			./lib/my/handle_e.c	\
			./lib/my/my_put_e.c	\
			./lib/my/my_put_up_e.c	\
			./lib/my/handle_up_e.c	\
			./lib/my/handle_f.c	\
			./lib/my/handle_up_f.c	\
			./lib/my/handle_g_and_upcase_g.c	\
			./lib/my/handle_n.c	\
			./lib/my/handle_o.c	\
			./lib/my/handle_p.c	\
			./lib/my/handle_prct.c	\
			./lib/my/handle_s.c	\
			./lib/my/handle_u.c	\
			./lib/my/handle_x.c	\
			./lib/my/handle_upcase_x.c	\
			./lib/my/my_put_up_e.c
##Fonctions utiles
CFILES +=	./lib/my/my_is_digit.c	\
			./lib/my/my_atoi.c	\
			./lib/my/my_min.c    \
## Fonctions de la piscine
CFILES +=	./lib/my/my_putchar.c	\
			./lib/my/my_isneg.c	\
			./lib/my/my_put_nbr.c	\
			./lib/my/my_swap.c	\
			./lib/my/my_putstr.c	\
			./lib/my/my_strlen.c	\
			./lib/my/my_getnbr.c	\
			./lib/my/my_sort_int_array.c	\
			./lib/my/my_compute_power_rec.c	\
			./lib/my/my_compute_square_root.c	\
			./lib/my/my_is_prime.c	\
			./lib/my/my_find_prime_sup.c	\
			./lib/my/my_strcpy.c	\
			./lib/my/my_strncpy.c	\
			./lib/my/my_revstr.c	\
			./lib/my/my_strstr.c	\
			./lib/my/my_strcmp.c	\
			./lib/my/my_strncmp.c	\
			./lib/my/my_strupcase.c	\
			./lib/my/my_strlowcase.c	\
			./lib/my/my_strcapitalize.c	\
			./lib/my/my_str_isalpha.c	\
			./lib/my/my_str_isnum.c	\
			./lib/my/my_str_islower.c	\
			./lib/my/my_str_isupper.c	\
			./lib/my/my_str_isprintable.c	\
			./lib/my/my_showstr.c	\
			./lib/my/my_showmem.c	\
			./lib/my/my_strcat.c	\
			./lib/my/my_strncat.c	\
			./lib/my/my_str_to_word_array_su.c

OFILES	=	$(CFILES:.c=.o)

LIBNAME	=	libmy.a
BINARY_NAME =	setting_up

all:    $(LIBNAME) $(BINARY_NAME) clean

$(LIBNAME):	$(OFILES)
	ar rc $(LIBNAME) $(OFILES)

$(BINARY_NAME): $(LIBNAME)
	gcc -g -o $(BINARY_NAME) $(CFLAGS) -L. -lmy

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(LIBNAME) $(BINARY_NAME) unit_tests

re: fclean all
	rm -f $(OFILES)
##Ne pas oublier de changer les tests
unit_tests: fclean $(LIBNAME)
	gcc -o unit_tests tests/tests_my_printf.c my_printf.c \
	-Include/my.h -L./ -lmy -lcriterion --coverage
tests_run: unit_tests
	./unit_tests
