CC = gcc

CFLAGS = -I$(LIBDIR) -c -Wall -Wextra -Werror
LFLAGS = -L$(LIBDIR) -llibft

NAME = push_swap
LIBDIR = libft
LIB = $(LIBDIR)/libft.a

SRC = main.c stacks.c
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) $(OBJ) $(LIB) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $<

$(LIB):
	$(MAKE) -C $(LIBDIR) bonus

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBDIR) fclean

re: fclean all

.PHONY: fclean clean re