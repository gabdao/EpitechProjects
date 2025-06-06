##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Simple Makefile for compiling 102architect
##

BIN_NAME =	104neutrinos
SRC      =	./src/main.c	\
			./src/nb_values.c	\
			./src/arithmetic_mean.c	\
			./src/harmonic_mean.c 	\
			./src/standard_deviation.c	\
			./src/root_mean_square.c

FLAG	= -lm -Iinclude
all:    $(BIN_NAME)

$(BIN_NAME): $(SRC)
	gcc -o $(BIN_NAME) $(SRC) $(FLAG)

clean:
	rm -f $(BIN_NAME)

re: clean all
