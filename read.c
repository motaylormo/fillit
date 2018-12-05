/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 10:34:08 by mtaylor           #+#    #+#             */
/*   Updated: 2018/12/03 13:34:24 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int        get_first_piece(t_tetri **tetri, int fd, int nth)
{
        char        buf[TETRI_SIZE];

        if ((read(fd, buf, TETRI_SIZE) == TETRI_SIZE)
                        && check_block(buf) == 1)
        {
                (*tetri) = create_tetri(buf, nth);
                return (1);
        }
        return (-1);
}

static int        get_a_piece(t_tetri **tetri, int fd, int nth)
{
        char        buf[TETRI_SIZE];
        t_tetri        *head;

        head = (*tetri);
        RET_IF((read(fd, buf, 1) == 0), 0);
        RET_IF(nth > MAX_TETRIS || (buf[0] != '\n'), -1);
        if ((read(fd, buf, TETRI_SIZE) == TETRI_SIZE) &&
                        check_block(buf) == 1)
        {
                while ((*tetri)->next)
                        (*tetri) = (*tetri)->next;
                (*tetri)->next = create_tetri(buf, nth);
                (*tetri) = head;
                return (1);
        }
        return (-1);
}

/*
** Opens file and - one tetri at a time - reads into the buffer,
** checks if it's a valid tetri piece, then makes it into a list node.
** Returns NULL and deletes the list of tetris if any piece is invalid.
*/

t_tetri                *get_tetris_pieces_from_file(const char *filename)
{
        int                fd;
        int                nth;
        int                ret;
        t_tetri        *head;

        fd = open(filename, O_RDONLY);
        RET_IF((fd < 1), NULL);
        nth = 0;
        head = NULL;
        ret = 1;
        while (ret == 1)
        {
                if (nth == 0)
                        ret = get_first_piece(&head, fd, nth);
                else
                        ret = get_a_piece(&head, fd, nth);
                nth++;
                if (ret == -1)
                {
                        free_tetri_list(&head);
                        return (NULL);
                }
        }
        close(fd);
        return (head);
}
