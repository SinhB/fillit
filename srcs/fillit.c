/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:29:17 by ybecret           #+#    #+#             */
/*   Updated: 2017/01/11 18:37:23 by ybecret          ###   ########.fr       */
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
        return ((i - count) / 16);
}
