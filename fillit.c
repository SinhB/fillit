/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:29:17 by ybecret           #+#    #+#             */
/*   Updated: 2017/02/18 16:07:30 by ybecret          ###   ########.fr       */
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

int	fill_tetris(t_tetris *tetris, char *buff, int nb_piece)
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
                printf("%s\n", "hello");
		while ((*buff == '.' || *buff == '\n') && (*buff != '#'))
                {
			i++;
                        buff++;
                }
                printf("%s\n", "world");
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
                printf("valeur de k : %d\n", k);
                printf("valeur de i : %d\n", i);
		if (k < 16 && i == 21)
		{
			while (k != 16)
                        {
				tmp[k] = '0';
                                k++;
                        }
		}
                tmp[k] = '\0';
		ft_strcpy(tetris[j].piece, tmp);
		tetris[j].index = j;
                printf("index : %d\n", j);
		j++;
	}
        return (0);
}

int		fillit(int fd)
{
	int			ret;
	char		buff[BUFF_SIZE +1];
	t_tetris	*tetris;
        int i;                  //pour test d'affichage
        char *tmp;              //pour test d'affichage

	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
        printf("%s\n", "salut0");
	first_check(buff);
        printf("%s\n", "salut1");
	tetris = (t_tetris*)malloc(sizeof(tetris) * (nb_tetriminos(buff)));
        printf("%s\n", "salut_malloc");
	if (tetris == NULL)
		check_errors(0);
        printf("%s\n", "salut2");
	fill_tetris(tetris, buff, nb_tetriminos(buff)); //remplissage de la strcture a partir du buffer
        printf("%s\n", "salut3");
        i = 0;                                  //affichage
        while (i < nb_tetriminos(buff))
	{
		tmp = tetris[i].piece;
		printf("string :");
		printf("%d %s", i, tetris[i].piece);
		printf("\n");
		i++;
	}
        printf("valeur de i : %d\n", i);
        test_tetris(tetris, nb_tetriminos(buff));  //comparaison
        printf("%s\n", "tetriminos valides !");
        return (0);
}
