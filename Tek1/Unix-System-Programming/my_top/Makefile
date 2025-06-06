##
## EPITECH PROJECT, 2024
## First makefile
## File description:
## Makefile that create lib, make tests and run them
##

BINARY_NAME =	my_top
SRC      =	./src/main.c	\
			./src/data.c	\
			./src/upper_section.c
CFLAGS = -Iinclude -lncurses

all:	$(BINARY_NAME)

$(BINARY_NAME): $(SRC)
	gcc -o $(BINARY_NAME) $(SRC) $(CFLAGS)

clean:
	rm -f $(BINARY_NAME)

re: clean all
