/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 10:35:25 by mtaylor           #+#    #+#             */
/*   Updated: 2018/12/03 13:04:25 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Make sure that there are newlines where and only where there should be
** (ie. spots 4, 9, 14, and 19)
** and that there are no characters other than '#' and '.'
** and that there are exactly 4 '#' and 12 '.'
*/

static int	check_chars(char *str)
{
	int i;
	int	block;
	int empty;

	i = 0;
	block = 0;
	empty = 0;
	while (i < TETRI_SIZE)
	{
		if (i % 5 == 4 && str[i] == '\n')
			i++;
		else if (i % 5 != 4 && (str[i] == BLOCK || str[i] == EMPTY))
		{
			if (str[i] == BLOCK)
				block++;
			if (str[i] == EMPTY)
				empty++;
			i++;
		}
		else
			return (0);
	}
	RET_IF((block == 4 && empty == 12), 1);
	return (0);
}

/*
** Counts places where two '#'s align on one axis
** and are off by exact 1 on the other axis.
*/

static int	count_touches(int b[4][2])
{
	int x;
	int i;
	int touches;

	touches = 0;
	x = 1;
	while (x < 4)
	{
		i = 1;
		while (i <= x)
		{
			if (b[x - i][0] == (b[x][0] - 1) && b[x - i][1] == b[x][1])
				touches++;
			if (b[x - i][1] == (b[x][1] - 1) && b[x - i][0] == b[x][0])
				touches++;
			i++;
		}
		x++;
	}
	return (touches);
}

/*
** Makes a little array of what the x and y value of each '#' will be
** then calls count_touches
** All valid pieces have 3 touches, execpt the square piece which has 4.
*/

static int	check_touching(char *str)
{
	int	b[4][2];
	int i;
	int x;
	int touches;

	i = 0;
	x = 0;
	while (i < TETRI_SIZE)
	{
		if (str[i] == BLOCK)
		{
			b[x][0] = i % 5;
			b[x][1] = i / 5;
			x++;
		}
		i++;
	}
	touches = count_touches(b);
	RET_IF((touches == 3 || touches == 4), 1);
	return (0);
}

/*
** Checks the characters
** and how many times '#' pieces touch each other
** Returns 1 if piece is valid, 0 if invalid
*/

int			check_block(char *str)
{
	RET_IF((check_chars(str) == 0), 0);
	RET_IF((check_touching(str) == 0), 0);
	return (1);
}
