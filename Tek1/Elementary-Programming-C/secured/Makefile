##
## EPITECH PROJECT, 2024
## First makefile
## File description:
## Makefile that create lib, make tests and run them
##

SRC = ./src/new_hashtable.c \
      ./src/hash_data.c \
      ./src/hash_handling.c \
      ./src/error_handling.c \

PRINTF_FILES = ./lib/my/my_printf.c \
               ./lib/my/handle_g.c \
               ./lib/my/my_put_unsigned_nbr.c \
               ./lib/my/my_putfloat.c \
               ./lib/my/handle_c.c \
               ./lib/my/handle_d_i.c \
               ./lib/my/handle_e.c \
               ./lib/my/my_put_e.c \
               ./lib/my/my_put_up_e.c \
               ./lib/my/handle_up_e.c \
               ./lib/my/handle_f.c \
               ./lib/my/handle_up_f.c \
               ./lib/my/handle_g_and_upcase_g.c \
               ./lib/my/handle_n.c \
               ./lib/my/handle_o.c \
               ./lib/my/handle_p.c \
               ./lib/my/handle_prct.c \
               ./lib/my/handle_s.c \
               ./lib/my/handle_u.c \
               ./lib/my/handle_x.c \
               ./lib/my/handle_upcase_x.c \
               ./lib/my/my_put_up_e.c     \
               ./lib/my/my_compute_power_rec.c     \

UTIL_FILES = ./lib/my/my_strlen.c   \
            ./lib/my/my_putchar.c   \
            ./lib/my/my_strcmp.c    \
            ./lib/my/my_strdup.c    \
            ./lib/my/my_put_nbr.c   \
            ./lib/my/my_putstr.c    \

SRC += $(PRINTF_FILES) $(UTIL_FILES)

OBJ = $(SRC:.c=.o)

BINARY_NAME = libhashtable.a

CFLAGS = -Iinclude

all: $(BINARY_NAME)

$(BINARY_NAME): $(OBJ)
	ar rc $(BINARY_NAME) $(OBJ)
	ranlib $(BINARY_NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(BINARY_NAME)

re: fclean all
