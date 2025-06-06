##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRC	=       my_putchar.c				\
			my_put_nbr.c				\
			my_atoi.c                   \
			my_putstr.c					\
			my_strlen.c					\
			my_strcpy.c					\
			my_strcmp.c					\
			my_strncmp.c				\
			my_strcat.c					\
			my_strdup.c 				\
			my_str_to_word_array.c		\
        	my_strncpy.c				\
        	my_getnbr.c					\
			free_array.c				\
			mini_printf.c				\
			error_printing.c			\
			get_file_size.c				\


CFLAGS	+=	-iquote ../include

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all:	 $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(CLAGS) $(OBJ)

clean:
	rm -f $(NAME) $(OBJ)

fclean: clean
	rm -f $(NAME) $(OBJ)

re:	fclean all
