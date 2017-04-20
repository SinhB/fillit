/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:29:17 by ybecret           #+#    #+#             */
/*   Updated: 2017/04/20 14:26:43 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		nb_tetriminos(char *buff)
{
	int i;
	int cnt;
	int nb_bloc;

	i = 0;
	cnt = 0;
	nb_bloc = 0;
	while (*buff && i++ != (BUFF_SIZE + 1))
	{
		if (*buff == '#')
			nb_bloc++;
		if (*buff != '#' && *buff != '.' && *buff != '\n')
			check_errors(3);
		if (*buff == '\n' && *(buff + 1) == '\n' && *(buff + 2) == '\n')
			check_errors(3);
		if (*buff++ == '\n')
			cnt++;
	}
	if ((((i - cnt) / 16) * 4) != nb_bloc)
		check_errors(3);
	if ((i - cnt) % 16 != 0)
		check_errors(3);
	if ((((i - cnt) / 16) * 5 - 1) != cnt)
		check_errors(3);
	return ((i - cnt) / 16);
}

char	*to_theleft(char *piece, int i, int j, int test)
{
	char	tmp[17];

	ft_strcpy(tmp, piece);
	if (piece[0] == '0' && piece[4] == '0' && piece[8] == '0' \
		&& piece[12] == '0')
	{
		while (i < 16)
		{
			tmp[j] = piece[i];
			j++;
			i++;
		}
		while (j != 16)
		{
			tmp[j] = '0';
			j++;
		}
		test = 0;
	}
	if (test == 0)
	{
		to_theleft(tmp, 1, 0, 1);
	}
	ft_strcpy(piece, tmp);
	return (piece);
}

char	*ft_replace(char *piece, int i, int j, int test)
{
	char	tmp[17];

	ft_strcpy(tmp, piece);
	if (piece[0] == '0' && piece[1] == '0' && piece[2] == '0' \
		&& piece[3] == '0')
	{
		while (i < 16)
		{
			tmp[j] = piece[i];
			i++;
			j++;
		}
		while (j != 16)
		{
			tmp[j] = '0';
			j++;
		}
		test = 0;
	}
	if (test == 0)
		ft_replace(tmp, 4, 0, 1);
	if (test == 1)
		to_theleft(tmp, 1, 0, 1);
	ft_strcpy(piece, tmp);
	return (piece);
}

int		fill_tetris(t_tetris *tetris, char *buff, int nb_piece, int j)
{
	int		i;
	int		k;
	char	tmp[17];

	while (j < nb_piece && *buff)
	{
		k = 0;
		i = 0;
		while (i < 21)
		{
			if (*buff == '.' || *buff == '#')
			{
				tmp[k] = (*buff == '.' ? '0' : '1');
				k++;
			}
			buff++;
			i++;
		}
		tmp[k] = '\0';
		ft_replace(tmp, 4, 0, 1);
		ft_strcpy(tetris[j].piece, tmp);
		j++;
	}
	return (0);
}

int		fillit(int fd)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	t_tetris	*tetris;
	int			nb_piece;

	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	first_check(buff);
	nb_piece = nb_tetriminos(buff);
	tetris = (t_tetris*)malloc(sizeof(t_tetris) * (nb_piece));
	if (tetris == NULL)
		check_errors(0);
	fill_tetris(tetris, buff, nb_piece, 0);
	test_tetris(tetris, nb_piece);
	fill_pos(tetris, nb_piece);
	fill_grid(tetris, nb_piece);
	free(tetris);
	return (0);
}
