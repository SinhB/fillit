/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:46:21 by ybecret           #+#    #+#             */
/*   Updated: 2017/02/21 19:49:15 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     print_grid(char **grid, int size)
{
        int i;

        i = 0;
        printf("size : %d\n", size);
        while (i < size)
        {
                ft_putstr_fd(grid[i], 1);
                ft_putstr_fd("\n", 1);
                i++;
        }
        printf("%s\n", "aurevoir");
        return (0);
}
