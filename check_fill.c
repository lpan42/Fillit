/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:25:26 by lpan              #+#    #+#             */
/*   Updated: 2018/12/06 14:25:29 by lpan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_fill(t_tetrimino_list *list, char *map, int size, int xy[])
{
	int				abcd[4];
	t_coordinate	*block;
	int				i;

	block = list->block;
	i = -1;
	while (++i < 4 && block[i].y + xy[1] < size && block[i].x + xy[0] < size)
		abcd[i] = (block[i].y + xy[1]) * (size + 1) + (block[i].x + xy[0]);
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
