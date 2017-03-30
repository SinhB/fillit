/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 19:44:59 by ybecret           #+#    #+#             */
/*   Updated: 2017/03/30 18:04:22 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    init_pos(t_tetris *tetris, int index)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(tetris[index].piece[i] != '\0')
    {
            if (tetris[index].piece[i] == '1')
            {
                    tetris[index].position[0][j] = i % 4;
                    tetris[index].position[1][j] = i / 4;
                    j++;
            }
            i++;
    }
}

void    fill_pos(t_tetris *tetris, int nb_piece)
{
        int i;

        i = 0;
        while(i < nb_piece)
        {
                init_pos(tetris, i);
                i++;
        }

}

int     fill_grid(t_tetris *tetris, int nb_piece)
{
        char    **grid;
        int     size;

        printf("%s\n", "salut");
        printf("nb_tetriminos : %d\n", nb_piece);
        size = ft_sqrt(nb_piece * 4);
        printf("grid size : %d\n", size);
        if (!(grid = (char**)malloc(sizeof(char*) * size)))
                check_errors(0);
        while (size)
        {
                set_grid(grid, size);
                if (backtracking(tetris, grid, size, nb_piece, 0, 0) == 1)
                {
                        free_grid(grid, size);
                        printf("a bientot\n");
                        return (0);
                }
                free_grid(grid, size);
                size++;
        }
        return (0);
}
