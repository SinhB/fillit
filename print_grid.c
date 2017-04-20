/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 15:46:21 by ybecret           #+#    #+#             */
/*   Updated: 2017/04/20 17:33:24 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_grid(char **grid, int size, int *cnt)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putstr_fd(grid[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	*cnt = 1;
}
