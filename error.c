/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 06:01:27 by dolee             #+#    #+#             */
/*   Updated: 2018/12/03 12:22:03 by dolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"

void	fillit_error_free_memory(t_tetrimino_list *list)
{
	delete_list(list);
	write(1, "error\n", 6);
	exit(0);
}

void	fillit_error(void)
{
	write(1, "error\n", 6);
	exit(0);
}
