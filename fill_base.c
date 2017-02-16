/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:20:47 by ybecret           #+#    #+#             */
/*   Updated: 2017/02/15 20:48:22 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list* fill_true(void)
{
        t_list *base;

        base = (t_list*)malloc(sizeof(t_list) * 19);
        base[1].tetriminos = "1000100010001000";
        base[2].tetriminos = "1111000000000000";
        base[3].tetriminos = "1101100000000000";
        base[4].tetriminos = "1000110001000000";
        base[5].tetriminos = "1100011000000000";
        base[6].tetriminos = "1001100100000000";
        base[7].tetriminos = "1100110000000000";
        base[8].tetriminos = "1000100110000000";
        base[9].tetriminos = "1000111000000000";
        base[10].tetriminos = "1011100000000000";
        base[11].tetriminos = "1100100010000000";
        base[12].tetriminos = "1110001000000000";
        base[13].tetriminos = "1001110000000000";
        base[14].tetriminos = "1000110010000000";
        base[15].tetriminos = "1110010000000000";
        base[16].tetriminos = "1001100010000000";
        base[17].tetriminos = "1000100011000000";
        base[18].tetriminos = "1110100000000000";
        base[19].tetriminos = "1100010001000000";
        return(base);
}
