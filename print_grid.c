/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:46:21 by ybecret           #+#    #+#             */
/*   Updated: 2017/04/06 10:26:38 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    print_grid(char **grid, int size, int *cnt)
{
        int  i;

        i = 0;
        printf("size : %d\n", size);
        while (i < size)
        {
                printf("%s\n", grid[i]);
                //ft_putstr_fd(grid[i], 1);
                //ft_putstr_fd("\n", 1);
                i++;
        }
        printf("%s\n", "aurevoir");
		*cnt = 1;
}

void    print_pos(t_tetris *tetris, int index)
{
        int i;
        int j;

        i = 0;
        while (i < index)
        {
                printf("piece numero :%d\n", i);
                j = 0;
                while (j < 4)
                {
                        printf("%d", tetris[i].position[0][j]);
                        j++;
                }
                printf("%c",'\n');
                j = 0;
                while (j < 4)
                {
                        printf("%d", tetris[i].position[1][j]);
                        j++;
                }
                printf("%c",'\n');
                i++;
        }
}
