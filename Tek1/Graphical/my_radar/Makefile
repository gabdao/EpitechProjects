##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Simple Makefile for compiling My Hunter
##

BIN_NAME =	my_radar
SRC      =	./src/main.c	\
			./src/handling_script_files.c	\
			$(wildcard ./lib/my/*.c)


CSFML_FLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio
CFLAGS   = -I./include -I./lib/my

all:    $(BIN_NAME)

$(BIN_NAME): $(SRC)
	gcc -o $(BIN_NAME) $(SRC) $(CFLAGS) $(CSFML_FLAGS)

clean:
	rm -f $(BIN_NAME)

re: clean all
