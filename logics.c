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

static int count_terimino(t_tetrimino_list *list)
{
	int i;
	t_tetrimino_list *ptr;

	i = 0;
	ptr = list;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

void	find_answer(t_tetrimino_list *list)
{
	int		sqr_size;
	char	*map;
	int		i;

	sqr_size = ft_sqrt(count_terimino(list) * 4);
	while (1)
	{
		if (!(map = (char *)malloc(sizeof(char) * sqr_size * (sqr_size + 1))))
			fillit_error_free_memory(list);
		memset((void *)map, '.', sqr_size * sqr_size);
		i = -1;
		while (++i < sqr_size)
			map[i * (sqr_size + 1) + sqr_size] = '\n';
		if (recursive(list, map, sqr_size))
		{
			write(1, map, sqr_size * (sqr_size + 1));
			free(map);
			delete_free(list);
			exit(0);
		}
		free(map);
		sqr_size++;
	}
}

static int	recursive(t_tetrimino_list *list, char *map, int sqr_size)
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

static int	check_fill(t_tetrimino_list *list, char *map, int size, int xy[])
{
	int				abcd[4];
	t_coordinate	*block;
	int				i;

	block = list->block;
	i = -1;
	while (++i < 4 && block[i].y + xy[1] < size && block[i].x + xy[0] < size)
		abcd[i] = (block[i].y + xy[1]) * (size + 1) + (block[i].x + xy[0]);
//	abcd[1] = (block[1].y + xy[1]) * (size + 1) + (block[1].x + xy[0]);
//	abcd[2] = (block[2].y + xy[1]) * (size + 1) + (block[2].x + xy[0]);
//	abcd[3] = (block[3].y + xy[1]) * (size + 1) + (block[3].x + xy[0]);
	if (map[abcd[0]] == '.')
		if (map[abcd[1]] == '.')
			if (map[abcd[2]] == '.')
				if (map[abcd[3]] == '.')
				{
					map[abcd[0]] = list->alphabet;
					map[abcd[1]] = list->alphabet;
					map[abcd[2]] = list->alphabet;
					map[abcd[3]] = list->alphabet;
					if (recursive(list->next, map, size))
						return (1);
					map[abcd[0]] = '.';
					map[abcd[1]] = '.';
					map[abcd[2]] = '.';
					map[abcd[3]] = '.';
				}
	return (0);
}
