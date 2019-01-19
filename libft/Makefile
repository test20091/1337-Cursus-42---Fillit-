# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arasfi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/05 16:22:23 by arasfi            #+#    #+#              #
#    Updated: 2018/10/08 06:05:36 by arasfi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c -Iincludes ft*.c -I libft.h
	ar rc $(NAME) ft*.o
	ranlib $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
