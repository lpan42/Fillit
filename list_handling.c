/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 05:49:53 by dolee             #+#    #+#             */
/*   Updated: 2018/12/03 13:40:05 by dolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "fillit.h"

t_tetrimino_list	*make_list(t_tetrimino_list **list)
{
	if (!(*list = (t_tetrimino_list *)malloc(sizeof(t_tetrimino_list))))
		fillit_error(void);
	(*list)->next = NULL;
	return (*list);
}

void				delete_list(t_tetrimino_list *list)
{
	t_tetrimino_list	*temp;

	while (list)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
}
