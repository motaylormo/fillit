/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:14:50 by jtaylor           #+#    #+#             */
/*   Updated: 2018/12/03 12:29:49 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_next_point(t_point **point, t_square *square)
{
	RET_IF((!square), 0);
	(*point)->y++;
	while ((*point)->x < square->size)
	{
		while ((*point)->y < square->size)
		{
			return (1);
			(*point)->y++;
		}
		(*point)->y = 0;
		(*point)->x++;
	}
	free_point(point);
	return (0);
}

int		solve_a_square(t_square *square, t_tetri *tetri, t_point *point)
{
	if (!tetri)
	{
		free_point(&point);
		return (1);
	}
	while (!(check_tetri_fits(tetri, square, point)))
	{
		RET_IF(!(get_next_point(&point, square)), 0);
	}
	place_a_tetri(tetri, square, point);
	if (!solve_a_square(square, tetri->next, create_point(0, 0)))
	{
		remove_a_tetri(tetri, square);
		RET_IF(!(get_next_point(&point, square)), 0);
		return (solve_a_square(square, tetri, point));
	}
	free_point(&point);
	return (1);
}

int		solve_squares(t_tetri *tetri_list)
{
	t_square	*square;
	size_t		square_size;

	RET_IF(!tetri_list, 0);
	square_size = 2;
	RET_IF((!(square = create_square(square_size))), 0);
	while (!solve_a_square(square, tetri_list, create_point(0, 0)))
	{
		free_square(&square);
		RET_IF((!(square = create_square(++square_size))), 0);
	}
	ft_putstrarr(square->rows);
	free_square(&square);
	free_tetri_list(&tetri_list);
	return (1);
}
