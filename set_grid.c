/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:26:24 by ybecret           #+#    #+#             */
/*   Updated: 2017/04/20 17:20:34 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int nb)
{
	int i;

	i = 0;
	while (i * i < nb)
		i++;
	return (i);
}

void	init_grid(char **grid, int size)
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
		grid[j][i] = '\0';
		j++;
	}
}

void	free_grid(char **grid, int size)
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

void	set_grid(char **grid, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		grid[i] = ft_strnew(size);
		i++;
	}
	init_grid(grid, size);
}
