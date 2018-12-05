/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:18:49 by jtaylor           #+#    #+#             */
/*   Updated: 2018/11/30 13:21:15 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char        **make_square_str(int size)
{
        char        **square;
        int                i;

        if ((square = (char **)ft_memalloc((sizeof(*square) * (size + 1)))))
        {
                i = 0;
                while (i < size)
                {
                        if (!(square[i] = ft_strnew(size)))
                        {
                                while (--i)
                                        ft_strdel(&square[i]);
                                free(square);
                                return (NULL);
                        }
                        ft_memset(square[i++], EMPTY, size);
                }
        }
        return (square);
}

void                free_square(t_square **square)
{
        int        row;

        if (!square)
                return ;
        row = 0;
        while (row < (*square)->size)
                ft_strdel(&((*square)->rows[row++]));
        free((*square)->rows);
        (*square)->rows = NULL;
        free(*square);
        *square = NULL;
}

t_square        *create_square(int size)
{
        t_square *square;

        if ((square = (t_square *)ft_memalloc(sizeof(*square))))
        {
                if (!(square->rows = make_square_str(size)))
                {
                        free(square);
                        return (NULL);
                }
                square->size = size;
        }
        return (square);
}
