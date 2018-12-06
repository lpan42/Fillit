# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpan <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/09 14:42:19 by lpan              #+#    #+#              #
#    Updated: 2018/11/09 14:42:23 by lpan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADER = -I ./fillit.h
NAME = fillit
OBJECTS = $(SOURCES:.c=.o)
SOURCES = ./check_tetriminos.c\
			error.c\
			fileio.c\
			list_handling.c\
			logics.c\
			tetrimino_handling.c\
			main.c\
			libft/ft_memset.c\
			libft/ft_sqrt.c

$(NAME):
	$(CC) $(FLAGS) $(HEADER) -o $(NAME) $(SOURCES)

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
