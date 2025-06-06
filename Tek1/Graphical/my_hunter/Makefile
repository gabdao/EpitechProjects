##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Simple Makefile for compiling My Hunter
##

BIN_NAME =	my_hunter
SRC      =	./src/main.c	\
			./src/manage_events.c	\
			./src/dragon_animation.c	\
			./src/menu/menu.c	\
			./src/audio.c	\
			./src/menu/menu_elements.c

CSFML_FLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio
CFLAGS   = -I./include

all:    $(BIN_NAME)

$(BIN_NAME): $(SRC)
	gcc -o $(BIN_NAME) $(SRC) $(CFLAGS) $(CSFML_FLAGS)

clean:
	rm -f $(BIN_NAME)

re: clean all
