##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Simple Makefile for compiling solo stumper 1
##

BIN_NAME =	countwords	
SRC      =	countwords.c	\

FLAG	= -lm -Iinclude
all:    $(BIN_NAME)

$(BIN_NAME): $(SRC)
	gcc -o $(BIN_NAME) $(SRC) $(FLAG)

clean:
	rm -f $(BIN_NAME)

re: clean all
