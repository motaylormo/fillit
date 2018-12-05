/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:34:44 by mtaylor           #+#    #+#             */
/*   Updated: 2018/12/02 15:37:17 by jtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** checks if a tetri will fit at a given board point,
** return (1) if fits, and (0) if it doesn't;
*/

int                check_tetri_fits(t_tetri *tetri, t_square *square, t_point *point)
{
        int        x;
        int        y;

        x = 0;
        while (x < 4)
        {
                y = 0;
                while (y < 4)
                {
                        if (tetri->block[x][y] == 1 &&
                                ((x + point->x >= square->size || y + point->y >= square->size)
                                        || (square->rows[x + point->x][y + point->y] != EMPTY)))
                                return (0);
                        y++;
                }
                x++;
        }
        return (1);
}

/*
** draws a tetri in it's letter on the square,
** the top left corner of the tetri at the point specified
*/

void        place_a_tetri(t_tetri *tetri, t_square *square, t_point *point)
{
        int        x;
        int        y;

        x = 0;
        while (x < 4)
        {
                y = 0;
                while (y < 4)
                {
                        if (tetri->block[x][y] == 1)
                                square->rows[x + point->x][y + point->y] = tetri->letter;
                        y++;
                }
                x++;
        }
        tetri->start->x = point->x;
        tetri->start->y = point->y;
}

void        remove_a_tetri(t_tetri *tetri, t_square *square)
{
        int        x;
        int        y;

        x = 0;
        while (x < 4)
        {
                y = 0;
                while (y < 4)
                {
                        if (tetri->block[x][y] == 1)
                                square->rows[x + tetri->start->x][y + tetri->start->y] = EMPTY;
                        y++;
                }
                x++;
        }
}
