/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 19:27:13 by ybecret           #+#    #+#             */
/*   Updated: 2017/04/20 17:24:20 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		test_pos(char **grid, t_tetris *tetris, int index, int pos_spe)
{
	int x;
	int y;
	int cnt;
	int size;

	cnt = 0;
	size = tetris->size;
	while (cnt < 4)
	{
		x = tetris[index].position[0][cnt] + POSX;
		y = tetris[index].position[1][cnt] + POSY;
		if ((y >= size) || (y >= size))
			return (1);
		if (grid[y][x] == '.')
			cnt++;
		else
			return (1);
	}
	return (0);
}

void	place_piece(char **grid, t_tetris *tetris, int index, int pos_spe)
{
	int x;
	int y;
	int cnt;
	int size;

	cnt = 0;
	size = tetris->size;
	tetris[index].pos_spe = pos_spe;
	while (cnt < 4)
	{
		x = tetris[index].position[0][cnt] + POSX;
		y = tetris[index].position[1][cnt] + POSY;
		grid[y][x] = index + 65;
		cnt++;
	}
}

void	delete_piece(char **grid, t_tetris *tetris, int index, int size)
{
	int x;
	int y;
	int cnt;
	int pos_spe;

	cnt = 0;
	pos_spe = tetris[index].pos_spe;
	while (cnt < 4)
	{
		x = tetris[index].position[0][cnt] + POSX;
		y = tetris[index].position[1][cnt] + POSY;
		grid[y][x] = '.';
		cnt++;
	}
	pos_spe = tetris[index - 1].pos_spe + 1;
	index = index - 1;
}

int		backtracking(t_tetris *tetris, char **grid, int size, int index)
{
	static int	cnt;
	int			pos_spe;

	pos_spe = 0;
	while (pos_spe <= size * size)
	{
		if (pos_spe == (size * size))
		{
			if (index == 0)
				return (2);
			delete_piece(grid, tetris, index - 1, size);
		}
		if (test_pos(grid, tetris, index, pos_spe) == 0)
		{
			place_piece(grid, tetris, index, pos_spe);
			if (index + 1 != tetris->nb_piece)
				backtracking(tetris, grid, size, index + 1);
			else if (index + 1 == tetris->nb_piece)
				print_grid(grid, size, &cnt);
			if (cnt)
				return (cnt);
		}
		pos_spe++;
	}
	return (0);
}
