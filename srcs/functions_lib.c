/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_lib.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:10:28 by ybecret           #+#    #+#             */
/*   Updated: 2017/01/11 18:17:58 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t     ft_strlen(char *s)
{
        int i;

        i = 0;
        while (s[i])
                i++;
        return (i);
}

void    ft_putstr_fd(char *s, int fd)
{
        write(fd, s, ft_strlen(s));
}

char    *ft_strnew(size_t size)
{
        char *new;

        if ((new = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
                check_errors(0);
        return (new);

}
