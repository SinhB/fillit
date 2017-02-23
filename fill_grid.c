/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 19:44:59 by ybecret           #+#    #+#             */
/*   Updated: 2017/02/22 22:30:11 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int     size_grid(int nb_tetriminos)
{
        return(ft_sqrt(nb_tetriminos * 4));
}

int     fill_grid(t_tetris *tetris, int nb_tetriminos)
{
        char    **grid;
        int     size;

        printf("%s\n", "salut");
        printf("nb_tetriminos : %d\n", nb_tetriminos);
        size = size_grid(nb_tetriminos);
        printf("grid size : %d\n", size);
        if (!(grid = (char**)malloc(sizeof(char*) * size)))
                check_errors(0);
        set_grid(grid, size);
        print_grid(grid, size);
        free_grid(grid, size);
        return (0);
}
