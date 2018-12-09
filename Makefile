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

CC = cc
FLAGS = -Wall -Wextra -Werror
HEADER = -I ./fillit.h
NAME = fillit
OBJECTS = $(SOURCES:.c=.o)
SOURCES = ./libft/ft_memset.c\
			libft/ft_sqrt.c\
			check_tetriminos.c\
			error.c\
			fileio.c\
			list_handling.c\
			logics.c\
			tetrimino_handling.c\
			main.c

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(HEADER) -o $(NAME) $(SOURCES)

$(SOURCES): %o : %c
	$(CC) -M -c $< $@

.PHONY: clean

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
