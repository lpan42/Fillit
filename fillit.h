/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:37:03 by dolee             #+#    #+#             */
/*   Updated: 2018/12/01 17:33:15 by dolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>

typedef struct				s_coordinate
{
	int	x;
	int	y;
}							t_coordinate;

typedef struct				s_tetrimino_list
{
	char					tetrimino[4][5];
	char					alphabet;
	t_coordinate			block[4];
	struct s_tetrimino_list	*next;
}							t_tetrimino_list;

int							main(int argc, char *argv[]);
t_tetrimino_list			*get_tetriminos_from_file(char *filename);
t_tetrimino_list			*make_list(t_tetrimino_list **list);
void						delete_list(t_tetrimino_list *list);
void						move_to_square_one(t_tetrimino_list *list);
int							check_fill(t_tetrimino_list *list, char *map,
	int size, int xy[]);
void						check_invalid_tetrimino(t_tetrimino_list *list);
void						find_answer(t_tetrimino_list *list);
void						fillit_error_free_memory(t_tetrimino_list *list);
void						fillit_error(void);
int							recursive(t_tetrimino_list *list, char *map,
	int sqr_size);
int							ft_sqrt(int nb);
void						*ft_memset(void *b, int c, size_t len);
#endif
