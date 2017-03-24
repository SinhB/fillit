/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:04:13 by ybecret           #+#    #+#             */
/*   Updated: 2017/02/12 19:56:01 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	check_errors(int i)
{
        if (i == 0)
                ft_putstr_fd("Memory allocation error\n", 1);
        else if (i == 1)
                ft_putstr_fd("open() error\n", 1);
        else if (i == 2)
                ft_putstr_fd("close() error\n", 1);
        else if (i == 3)
                ft_putstr_fd("error\n", 1);
        exit (EXIT_FAILURE);
}

void	first_check(char *buff)
{
        int i;
        int count;

        i = 1;
        count = 20;
        while (buff[i])
        {
                        if (i % count == 0 && buff [i] != '\n')
                                check_errors(3);
                        else //if ( i % count == 0 && buff[i] == '\n') inutile
                                count += 21;
                        i++;
        }
}
