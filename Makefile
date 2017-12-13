NAME = fillit

LIBF = libft/

SRC =	validator.c \
		backtrack.c \
		get_shape.c \
		make_grid.c \
		main.c

all: $(NAME)

$(NAME):
	make all -C libft
	gcc -Wall -Werror -Wextra -o $(NAME) libft/libft.a $(SRC)

clean:
	/bin/rm -f *.o
	make clean -C libft

fclean: clean
	make fclean -C libft
	/bin/rm -f $(NAME)

re: fclean all
