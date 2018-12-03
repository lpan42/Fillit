/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 07:18:17 by dolee             #+#    #+#             */
/*   Updated: 2018/12/01 12:57:02 by dolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		move_up(t_tetrimino_list *list)
{
	if (list->block[0].y == 0)
		return (0);
	if (list->block[1].y == 0)
		return (0);
	if (list->block[2].y == 0)
		return (0);
	if (list->block[3].y == 0)
		return (0);
	list->block[0].y--;
	list->block[1].y--;
	list->block[2].y--;
	list->block[3].y--;
	return (1);
}

static int		move_left(t_tetrimino_list *list)
{
	if (list->block[0].x == 0)
		return (0);
	if (list->block[1].x == 0)
		return (0);
	if (list->block[2].x == 0)
		return (0);
	if (list->block[3].x == 0)
		return (0);
	list->block[0].x--;
	list->block[1].x--;
	list->block[2].x--;
	list->block[3].x--;
	return (1);
}

void			move_to_square_one(t_tetrimino_list *list)
{
	while (move_up(list))
		;
	while (move_left(list))
		;
}
