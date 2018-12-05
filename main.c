/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 05:44:12 by dolee             #+#    #+#             */
/*   Updated: 2018/12/03 13:02:23 by dolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char *argv[])
{
	t_tetrimino_list	*list;

	if (argc != 2)
		fillit_error(void);
	list = get_tetriminos_from_file(argv[1]);
	find_answer(list);
	return (0);
}
