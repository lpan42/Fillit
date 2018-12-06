/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fileio.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 07:01:36 by dolee             #+#    #+#             */
/*   Updated: 2018/12/03 15:35:03 by dolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "fillit.h"
#include <stdio.h>
t_tetrimino_list	*get_tetriminos_from_file(char *filename)
{
	int					fd;
	int					read_byte;
	char				buffer[2];
	t_tetrimino_list	*list[2];
	int					alphabet;


	read_byte = 1;
	fd = open(filename, O_RDONLY);
	alphabet = 64;
	//printf("fd: %d\n", fd);
	list[0] = make_list(&list[1]);
	//printf("start_element->alphabet: %c\n", start_element->alphabet);
	while (read_byte)
	{
		if ((read_byte = read(fd, list[1]->tetrimino, 20)) != 20)
			fillit_error_free_memory(list[1]);
				printf("while_start : %p\n", list[1]->next);
		//printf("read_byte: %d\n", read_byte);
		//printf("list->tetrimino: %c\n", list->tetrimino[1][2]);
		list[1]->alphabet = ++alphabet;
		//printf("list->alphabet: %d\n", list->alphabet);
		printf("before cit : %p\n", list[1]->next);
		check_invalid_tetrimino(list[1]);
		//printf("list->tetrimino: %c\n", list->tetrimino[0][2]);
		move_to_square_one(list[1]);
		if (!(~(read_byte = read(fd, buffer, 1)))
			|| (read_byte && *buffer != '\n'))
				fillit_error_free_memory(list[1]);
		if (read_byte)
			list[1] = make_list(&list[1]->next);
	}
		//printf("end of gtff : %p\n", list);
	close(fd);
	return (list[0]);
}
