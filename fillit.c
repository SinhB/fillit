/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:29:17 by ybecret           #+#    #+#             */
/*   Updated: 2017/02/23 22:24:49 by ybecret          ###   ########.fr       */
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
		while ((*buff == '.' || *buff == '\n') && (*buff != '#'))
                {
			i++;
                        buff++;
                }
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
		if (k < 16 && i == 21)
		{
			while (k != 16)
                        {
				tmp[k] = '0';
                                k++;
                        }
		}
                printf("valeur de k : %d\n", k);
                tmp[k] = '\0';
		ft_strcpy(tetris[j].piece, tmp);
		tetris[j].index = j;
                printf("index : %d\n", j);
                printf("%s %s\n", "piece :", tetris[j].piece);
		j++;
	}
        printf("valeur de j :%d\n", j);
        return (0);
}

int		fillit(int fd)
{
	int			ret;
	char		buff[BUFF_SIZE +1];
	t_tetris	*tetris;
        int i;                  //pour test d'affichage
        char *tmp;              //pour test d'affichage
        int             nb_piece;

	ret = read(fd, buff, BUFF_SIZE);
	buff[ret] = '\0';
        printf("%s\n", "salut0");
	first_check(buff);
        printf("%s\n", "salut1");
        nb_piece = nb_tetriminos(buff);
	tetris = (t_tetris*)malloc(sizeof(tetris) * (nb_piece));
        printf("%s\n", "salut_malloc");
	if (tetris == NULL)
		check_errors(0);
        printf("%s\n", "salut2");
	fill_tetris(tetris, buff, nb_piece); //remplissage de la strcture a partir du buffer
        printf("%s\n", "salut3");
        i = 0;                                  //affichage
        while (i < nb_piece)
	{
		tmp = tetris[i].piece;
		printf("string :");
		printf("%d %s", i, tetris[i].piece);
		printf("\n");
		i++;
	}
        printf("valeur de i : %d\n", i);
        test_tetris(tetris, nb_piece);  //comparaison
        printf("%s\n", "tetriminos valides !");
     //   fill_grid(tetris, nb_tetriminos(buff));
        fill_pos(tetris, nb_piece);  //remplissage coordonnee x y
        print_pos(tetris, nb_piece);  //affichage
        free(tetris);
        return (0);
}
