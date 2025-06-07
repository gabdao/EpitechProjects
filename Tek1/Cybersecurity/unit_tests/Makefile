##
## EPITECH PROJECT, 2025
## makefile
## File description:
## Makefile
##

NAME = unit_tests
SRC = unit_tests.c
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -lcriterion

all: $(NAME)

$(NAME): $(SRC)
	@gcc $(CFLAGS) -o $(NAME) $(SRC) $(LDFLAGS)

run: $(NAME)
	@./$(NAME)

clean:
	@rm -f $(NAME)

fclean: clean

re: fclean all
