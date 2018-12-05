# get_next_line
A `C` function that reads tetris pieces from a file, then uses recursive backtracking to find the smallest square they can be fit into.

My version of the 42 cadet project `fillit`. `fillit` is a group project, and I (mtaylor) did this project with [jtaylor](https://github.com/jt-taylor). Credit to him where it is due.

The tetri blocks are stored in the data structure `t_tetri`. The square grid that will ultimately be the solution is stored in the data structure `t_square`. During the solving stage, the top leftmost point of a tetri block's placement is stored in the data structure `t_point`.

It uses several functions for the previous project, `libft`, including `ft_memalloc`, `ft_strnew`, `ft_strdel`, `ft_memset`, `ft_putstr_fd`. `fillit` also uses the function `ft_putstrarr`, which was added to `libft` and is not one of the standard `libft` functions.
