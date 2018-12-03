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
#include "libft.h"

t_tetrimino_list	*get_tetriminos_from_file(char *filename)
{
	int					fd;
	int					read_byte;
	char				buffer[2];
	t_tetrimino_list	*start_element;
	t_tetrimino_list	*list;

	read_byte = 1;
	fd = open(filename, O_RDONLY);
	start_element = make_list(&list);
	start_element->alphabet = 64
	while (read_byte)
	{
		if ((read_byte = read(fd, list->tetrimino, 20)) != 20)
			fillit_error_free_memory(list);
		list->alphabet++;
		check_invalid_tetrimino(list);
		move_to_square_one(list);
		if (!(~(read_byte = read(fd, buffer, 1)) || *buffer != '\n')
			fillit_error_free_memory(list);
		if (read_byte)
			list = make_list(list->next);
	}
	close(fd);
	return (start_element);
}
