/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:53:00 by dolee             #+#    #+#             */
/*   Updated: 2018/12/03 17:42:26 by dolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"

static int	count_terimino(t_tetrimino_list *list)
{
	int					i;
	t_tetrimino_list	*ptr;

	i = 0;
	ptr = list;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

int			check_fill(t_tetrimino_list *list, char *map, int size, int xy[])
{
	int				abcd[4];
	t_coordinate	*block;
	int				i;
	int				a;

	block = list->block;
	i = -1;
	while (++i < 4 && block[i].y + xy[1] < size && block[i].x + xy[0] < size)
		abcd[i] = (block[i].y + xy[1]) * (size + 1) + (block[i].x + xy[0]);
	if (i < 4 && !(block[i].y + xy[1] < size && block[i].x + xy[0] < size))
		return (0);
	if (map[abcd[0]] == '.')
		if (map[abcd[1]] == '.')
			if (map[abcd[2]] == '.')
				if (map[abcd[3]] == '.')
				{
					a = -1;
					while (++a < 4)
						map[abcd[a]] = list->alphabet;
					if (recursive(list->next, map, size))
						return (1);
					while (--a > -1)
						map[abcd[a]] = '.';
				}
	return (0);
}

int			recursive(t_tetrimino_list *list, char *map, int sqr_size)
{
	int		xy[2];

	if (!list)
		return (1);
	xy[1] = 0;
	while (xy[1] < sqr_size)
	{
		xy[0] = 0;
		while (xy[0] < sqr_size)
		{
			if (check_fill(list, map, sqr_size, xy))
				return (1);
			xy[0]++;
		}
		xy[1]++;
	}
	return (0);
}

void		find_answer(t_tetrimino_list *list)
{
	int		sqr_size;
	char	*map;
	int		i;

	sqr_size = ft_sqrt(count_terimino(list) * 4);
	while (1)
	{
		if (!(map = (char *)malloc(sizeof(char) * sqr_size * (sqr_size + 1))))
			fillit_error_free_memory(list);
		ft_memset((void *)map, '.', sqr_size * (sqr_size + 1));
		i = -1;
		while (++i < sqr_size)
			map[i * (sqr_size + 1) + sqr_size] = '\n';
		if (recursive(list, map, sqr_size))
		{
			write(1, map, sqr_size * (sqr_size + 1));
			free(map);
			delete_list(list);
			exit(0);
		}
		free(map);
		sqr_size++;
	}
}
