/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kitrosse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:48:05 by kitrosse          #+#    #+#             */
/*   Updated: 2017/02/17 18:01:00 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct		s_list
{
	char			tetriminos[17];
}					t_list;

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

t_list*		fill_true(void)
{
	t_list *base;

	base = (t_list*)malloc(sizeof(t_list) * 19);
	ft_strcpy(base[0].tetriminos, "1000100010001000");
	ft_strcpy(base[1].tetriminos, "1111000000000000");
	ft_strcpy(base[2].tetriminos, "1101100000000000");
	ft_strcpy(base[3].tetriminos, "1000110001000000");
	ft_strcpy(base[4].tetriminos, "1100011000000000");
	ft_strcpy(base[5].tetriminos, "1001100100000000");
	ft_strcpy(base[6].tetriminos, "1100110000000000");
	ft_strcpy(base[7].tetriminos, "1000100110000000");
	ft_strcpy(base[8].tetriminos, "1000111000000000");
	ft_strcpy(base[9].tetriminos, "1011100000000000");
	ft_strcpy(base[10].tetriminos, "1100100010000000");
	ft_strcpy(base[11].tetriminos, "1110001000000000");
	ft_strcpy(base[12].tetriminos, "1001110000000000");
	ft_strcpy(base[13].tetriminos, "1000110010000000");
	ft_strcpy(base[14].tetriminos, "1110010000000000");
	ft_strcpy(base[15].tetriminos, "1001100010000000");
	ft_strcpy(base[16].tetriminos, "1000100011000000");
	ft_strcpy(base[17].tetriminos, "1110100000000000");
	ft_strcpy(base[18].tetriminos, "1100010001000000");
	return(base);
}

int			main(void)
{
	t_list *base;
	int		i;
	char	*tmp;

	base = fill_true();
	i = 0;
	while (i < 19)
	{
		tmp = base[i].tetriminos;
		printf("string :");
		printf("%d %s", i, base[i].tetriminos);
		printf("\n");
		i++;
	}
	return (0);
}
