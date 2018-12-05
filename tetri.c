/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 10:34:32 by mtaylor           #+#    #+#             */
/*   Updated: 2018/12/03 12:28:41 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetri                *top_justify(t_tetri *tetri)
{
        int row;
        int col;

        while (tetri->block[0][0] == 0 && tetri->block[0][1] == 0 &&
                        tetri->block[0][2] == 0 && tetri->block[0][3] == 0)
        {
                row = 0;
                while (row < 4)
                {
                        col = 0;
                        while (col < 4)
                        {
                                tetri->block[row][col] = (row == 3) ? 0 :
                                        tetri->block[row + 1][col];
                                col++;
                        }
                        row++;
                }
        }
        return (tetri);
}

static t_tetri                *left_justify(t_tetri *tetri)
{
        int col;
        int row;

        while (tetri->block[0][0] == 0 && tetri->block[1][0] == 0 &&
                        tetri->block[2][0] == 0 && tetri->block[3][0] == 0)
        {
                row = 0;
                while (row < 4)
                {
                        col = 0;
                        while (col < 4)
                        {
                                tetri->block[row][col] = (col == 3) ? 0 :
                                        tetri->block[row][col + 1];
                                col++;
                        }
                        row++;
                }
        }
        return (tetri);
}

t_tetri                                *create_tetri(char *str, int nth)
{
        t_tetri        *new;
        int                x;
        int                y;

        RET_IF(((new = (t_tetri*)malloc(sizeof(t_tetri))) == NULL), NULL);
        new->next = NULL;
        new->letter = 'A' + nth;
        new->start = create_point(0, 0);
        x = 0;
        while (x < 4)
        {
                y = 0;
                while (y < 4)
                {
                        new->block[x][y] = (*str == BLOCK) ? 1 : 0;
                        y++;
                        str++;
                }
                x++;
                str++;
        }
        new = left_justify(new);
        new = top_justify(new);
        return (new);
}

void                                free_tetri_list(t_tetri **start)
{
        t_tetri        *curr;
        t_tetri        *next;

        if (!start || !*start)
                return ;
        curr = *start;
        while (curr != NULL)
        {
                next = curr->next;
                free_point(&curr->start);
                free(curr);
                curr = next;
        }
        *start = NULL;
}
