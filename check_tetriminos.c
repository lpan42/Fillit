/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 08:20:43 by dolee             #+#    #+#             */
/*   Updated: 2018/11/30 12:42:07 by dolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	get_adjacent_blocks(char tetrimino[][5], int i, int j)
{
	int		cnt;

	cnt = 0;
	if (!i)
		if (tetrimino[i - 1][j] == '#')
			cnt++;
	if (!j)
		if (tetrimino[i][j - 1] == '#')
			cnt++;
	if (i != 3)
		if (tetrimino[i + 1][j] == '#')
			cnt++;
	if (j != 3)
		if (tetrimino[i][j + 1] == '#')
			cnt++;
	return (cnt);
}

static void	set_values(int *n, t_tetrimino_list *list, int *xy, int *b)
{
	n[0]++;
	n[1] += get_adjacent_blocks(list->tetrimino, xy[0], xy[1]);
	list->block[*b].x = xy[1];
	list->block[*b].y = xy[0];
	(*b)++;
}

void		check_invalid_tetrimino(t_tetrimino_list *list)
{
	int		xy[2];
	int		block_counts_n_adjacents[2];
	int		b;

	b = 0;
	xy[0] = -1;
	block_counts_n_adjacents[0] = 0;
	block_counts_n_adjacents[1] = 0;
	while (++(xy[0]) < 4)
	{
		xy[1] = -1;
		while (++(xy[1]) < 4)
			if (list->tetrimino[xy[0]][xy[1]] == '.')
				;
			else if (list->tetrimino[xy[0]][xy[1]] == '#')
				set_values(block_counts_n_adjacents, list, xy, &b);
			else
				fillit_error_free_memory(list);
		if (list->tetrimino[xy[0]][xy[1]] != '\n')
			fillit_error_free_memory(list);
	}
	if (block_counts_n_adjacents[0] != 4 || block_counts_n_adjacents[1] < 6)
		fillit_error_free_memory(list);
}
