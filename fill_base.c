/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:20:47 by ybecret           #+#    #+#             */
/*   Updated: 2017/02/18 16:02:50 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list* fill_valid(void)
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

int     test_tetris(t_tetris *tetris, int nb_tetriminos)
{
        t_list  *base;
        int     i;
        int     j;

        base = fill_valid();
        i = 0;
        while (i < nb_tetriminos)
        {
                j = 0;
                while ((ft_strcmp(tetris[i].piece, base[j].tetriminos)) != 0)
                {
                        printf("valeur de tetris[%d] : %s\n", i, tetris[i].piece);
                        printf("valeur de base[%d] : %s\n", j, base[j].tetriminos);
                        if (j == 19)
                        {
                                printf("valeur de i : %d\n", i);
                                printf("%s\n", "pas valides..");
                                check_errors(3);
                        }
                        j++;
                }
                i++;
        }
        return (0);
}
