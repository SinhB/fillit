/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:26:24 by ybecret           #+#    #+#             */
/*   Updated: 2017/03/30 16:20:44 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void init_grid(char **grid, int size)
{
        int i;
        int j;

        j = 0;
        while (j < size)
        {
                i = 0;
                while (i < size)
                {
                        grid[j][i] = '.';
                        i++;
                }
                j++;
        }
}

void    free_grid(char **grid, int size)
{
        int i;

        i = 0;
        while (i < size)
        {
                free(grid[i]);
                i++;
        }
        free(grid);
}

void     set_grid(char **grid, int size)
{
        int i;

        i = 0;
        printf("%s\n", "hola");
        /*if (!(grid = (char**)malloc(sizeof(char) * size)))
                check_errors(0);*/
        while (i < size)
        {
                grid[i] = ft_strnew(size);
                i++;
        }
        init_grid(grid, size);
}
