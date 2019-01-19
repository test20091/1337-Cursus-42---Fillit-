NAME = fillit

FLAGS = -Wall -Wextra -Werror

INCLUDES = ./includes

all: $(NAME)

$(NAME):
	make -C libft/
	gcc $(FLAGS) -c decale.c tetrishelper.c boardhelper.c verifyfile.c  main.c -I$(INCLUDES)
	ar rc $(NAME).a *.o
	ranlib $(NAME).a
	gcc $(FLAGS) libft/libft.a  $(NAME).a -o $(NAME)

clean:
	/bin/rm -f *.o && make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean
	/bin/rm -f *.o
	/bin/rm -f *.a

re: fclean all