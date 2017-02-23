/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:26:24 by ybecret           #+#    #+#             */
/*   Updated: 2017/02/22 22:34:56 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void init_grid(char **grid, int size)
{
        int i;
        int j;

        j = 0;
        while (j < size)
        {
                i = 0;
                while (grid[j][i] != '\0')
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
