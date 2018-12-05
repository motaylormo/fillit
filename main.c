/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaylor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:09:01 by jtaylor           #+#    #+#             */
/*   Updated: 2018/12/03 12:34:55 by mtaylor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** print usage message if wrong num parameters are given
*/

void	print_usage(char const *prog_name)
{
	ft_putstr_fd("usage: ", STDERR_FILENO);
	ft_putstr_fd(prog_name, STDERR_FILENO);
	ft_putstr_fd(" [input_file]\n", STDERR_FILENO);
}

/*
**	return (1)
**		both get_tetris_pieces_from_file and solve_squares return non zero
**		(meaning no errors)
**		and solve_squares prints the solution
**	return (0)
**		an error was found somewhere
**		so now the main will print "error\n" to stdout
*/

int		solve_or_error(char const *filename)
{
	t_tetri	*tetri_list;

	RET_IF((!(tetri_list = get_tetris_pieces_from_file(filename))), 0);
	RET_IF((!solve_squares(tetri_list)), 0);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		print_usage(argv[0]);
		return (1);
	}
	if (!solve_or_error(argv[1]))
		write(1, "error\n", 6);
	return (0);
}
