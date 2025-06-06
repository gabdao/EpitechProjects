##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Simple Makefile for compiling 102architect
##

BIN_NAME =	102architect
SRC      =	main.c
FLAG	= -lm
all:    $(BIN_NAME)

$(BIN_NAME): $(SRC)
	gcc -o $(BIN_NAME) $(SRC) $(FLAG)

clean:
	rm -f $(BIN_NAME)

re: clean all
