/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:29:17 by ybecret           #+#    #+#             */
/*   Updated: 2017/02/16 18:31:49 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     nb_tetriminos(char *buff)
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

void	fill_tetris(s_tetris *tetris, char *buff, int nb_piece)
{
	int		i;
	int		j;
	int		k;
	char	tmp[16];

	j = 0;
	while (j < nb_piece && *buff)
	{
		k = 0;
		i = 0;
		while (*buff == '.' || *buff == '\n')
			i++;
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
		if (k < 16 && i == 20)
		{
			while (k++ < 16)
				tmp[k] = '0';
		}
		tetris[j].piece = ft_strcpy(tetris[j].piece, tmp);
		tetris[j]->index = j;
		j++;
	}
}

int		fillit(int fd)
{
	int			ret;
	char		buff[BUFF_SIZE +1];
	s_tetris	*tetris;

	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
	first_check(buff);
	tetris = (tetris*)malloc(sizeof(tetris) * (nb_tetriminos(buff)));
	if (tetris == NULL)
		check_errors(0);
	fill_tetris(tetris, buff, nb_tetriminos(buff));
	
	
	
	
}
