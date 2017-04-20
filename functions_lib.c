/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_lib.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:10:28 by ybecret           #+#    #+#             */
/*   Updated: 2017/04/20 16:53:29 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

char	*ft_strnew(size_t size)
{
	char	*new;

	if ((new = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		check_errors(0);
	return (new);
}

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

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}
