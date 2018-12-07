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
	list[0] = make_list(&list[1]);
	while (read_byte)
	{
		if ((read_byte = read(fd, list[1]->tetrimino, 20)) != 20)
			fillit_error_free_memory(list[1]);
		list[1]->alphabet = ++alphabet;
		check_invalid_tetrimino(list[1]);
		move_to_square_one(list[1]);
		if (!(~(read_byte = read(fd, buffer, 1)))
			|| (read_byte && *buffer != '\n'))
			fillit_error_free_memory(list[1]);
		if (read_byte)
			list[1] = make_list(&list[1]->next);
	}
	close(fd);
	return (list[0]);
}
