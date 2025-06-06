##
## EPITECH PROJECT, 2024
## First makefile
## File description:
## Makefile that create lib with files.c and other things
##

CFILES	=	my_printf.c	\
		./lib/my/my_strlen.c	\
		./lib/my/handle_g.c	\
		./lib/my/my_compute_power_rec.c	\
		./lib/my/my_putchar.c	\
		./lib/my/my_put_nbr.c	\
		./lib/my/my_put_unsigned_nbr.c	\
		./lib/my/my_putstr.c	\
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
		./lib/my/my_put_up_e.c	\

OFILES	=	$(CFILES:.c=.o)

NAME	=	libmy.a

all:    $(NAME) clean

$(NAME):	$(OFILES)
	ar rc $(NAME) $(OFILES)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME) unit_tests

re: fclean all
	rm -f $(OFILES)

unit_tests: fclean $(NAME)
	gcc -o unit_tests tests/tests_my_printf.c my_printf.c \
	-Include/my.h -L./ -lmy -lcriterion
tests_run: unit_tests
	./unit_tests
