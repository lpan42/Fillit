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
		fillit_error();
	(*list)->next = NULL;
	return (*list);
}

void				delete_list(t_tetrimino_list *list)
{
	t_tetrimino_list	*temp;

	temp = 0;
	while (list)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
}

int					ft_sqrt(int nb)
{
	int result;

	result = 0;
	while (result * result <= nb)
	{
		if (result * result == nb)
			return (result);
		result++;
	}
	return (0);
}

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char *ptr;

	ptr = (unsigned char*)b;
	while (len > 0)
	{
		*ptr = (char)c;
		ptr++;
		len--;
	}
	return (b);
}
