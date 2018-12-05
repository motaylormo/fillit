/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 20:50:03 by jtaylor           #+#    #+#             */
/*   Updated: 2018/12/03 12:35:12 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_point	*create_point(int x, int y)
{
	t_point	*point;

	RET_IF(((point = (t_point*)malloc(sizeof(t_point))) == NULL), NULL);
	point->x = x;
	point->y = y;
	return (point);
}

void	free_point(t_point **point)
{
	if (!point)
		return ;
	free(*point);
	*point = NULL;
}
