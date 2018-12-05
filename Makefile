# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/16 19:30:49 by jtaylor           #+#    #+#              #
#    Updated: 2018/12/03 12:47:50 by mtaylor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRC = main.c \
	  read.c \
	  solve.c \
	  place_pieces.c \
	  validate.c \
	  tetri.c \
	  square.c \
	  point.c \

all : $(NAME)

$(NAME) :
	make -C ./libft
	gcc $(FLAGS) -I ./libft/includes $(SRC) ./libft/libft.a -o $(NAME)

clean :
	make -C libft clean

fclean : clean
	rm -rf $(NAME)
	make -C libft fclean

re : fclean all
