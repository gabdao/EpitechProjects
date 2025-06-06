##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Makefile for my_sudo
##

NAME	=	my_sudo

SRC	=	./src/main.c	\
		./src/handle_sudoers.c	\
		./src/env_data_handling.c	\
		./src/checking_password.c	\
		./src/execute_commands.c	\
		./src/handle_flags/handle_help.c	\
		./src/handle_flags/handle_user.c	\
		./src/handle_flags/handle_group.c	\
		./src/handle_flags/handle_shell.c	\
		./src/handle_flags/handle_login_shell.c	\
		./src/handle_flags/handle_background.c	\
		./src/handle_flags/handle_list.c	\
		./src/handle_flags/handle_validate.c	\
		./src/handle_flags/handle_invalidate_cache.c	\
		./src/handle_flags/handle_preserve_env.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-lm -Iinclude -lcrypt

all:    $(NAME) clean

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
