##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## Simple Makefile for compiling solo stumper 4
##

BIN_NAME =	USNameFormatter

SRC      =	main.c

FLAG	= -lm -iquote include

all:    $(BIN_NAME)

$(BIN_NAME): $(SRC)
	gcc -o $(BIN_NAME) $(SRC) $(FLAG)

clean:
	rm -f $(BIN_NAME)

re: clean all
