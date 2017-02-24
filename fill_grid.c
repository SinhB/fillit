/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 19:44:59 by ybecret           #+#    #+#             */
/*   Updated: 2017/02/23 22:04:28 by ybecret          ###   ########.fr       */
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

int     fill_grid(int nb_piece)
{
        char    **grid;
        int     size;

        printf("%s\n", "salut");
        printf("nb_tetriminos : %d\n", nb_piece);
        size = ft_sqrt(nb_piece * 4);
        printf("grid size : %d\n", size);
        if (!(grid = (char**)malloc(sizeof(char*) * size)))
                check_errors(0);
        set_grid(grid, size);
        print_grid(grid, size);
        free_grid(grid, size);
        return (0);
}
