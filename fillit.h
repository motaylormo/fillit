/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 10:33:48 by mtaylor           #+#    #+#             */
/*   Updated: 2018/12/03 13:12:21 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

/*
** <stdlib.h> for exit & malloc & free
** <fcntl.h>  for open
** <unistd.h> for close & write & read
*/
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

/*
** macros
*/
# define RET_IF(cond, ret) if (cond) return (ret)
# define BLOCK '#'
# define EMPTY '.'
# define TETRI_SIZE 20
# define MAX_TETRIS 26

/*
** structs
*/
typedef struct        s_square
{
        int                size;
        char        **rows;
}                                t_square;

typedef struct        s_point
{
        int                x;
        int                y;
}                                t_point;

typedef struct        s_tetri
{
        struct s_tetri        *next;
        char                        letter;
        int                                block[4][4];
        t_point                        *start;
}                                t_tetri;

/*
** main.c
*/
void                        print_usage(char const *prog_name);
int                                solve_or_error(char const *filename);
int                                main(int argc, char **argv);

/*
** square.c
*/
t_square                *create_square(int size);
void                        free_square(t_square **square);

/*
** point.c
*/
t_point                        *create_point(int x, int y);
void                        free_point(t_point **point);
/*
** tetri.c
*/
t_tetri                        *create_tetri(char *str, int nth);
void                        free_tetri_list(t_tetri        **head);

/*
** validate.c
*/
int                                check_block(char *str);

/*
 ** read.c
*/
t_tetri                        *get_tetris_pieces_from_file(const char *filename);

/*
** solve.c
*/
int                                get_next_point(t_point **point, t_square *square);
int                                solve_a_square(t_square *square, t_tetri *tetri,
                t_point *point);
int                                solve_squares(t_tetri *tetri_list);

/*
** place_pieces.c
*/
int                                check_tetri_fits(t_tetri *tetri, t_square *square,
                t_point *point);
void                        place_a_tetri(t_tetri *tetri, t_square *square, t_point *point);
void                        remove_a_tetri(t_tetri *tetri, t_square *square);

#endif
