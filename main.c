/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 17:53:30 by ybecret           #+#    #+#             */
/*   Updated: 2017/04/20 17:34:01 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			check_errors(1);
		fillit(fd);
		close(fd);
	}
	else
	{
		ft_putstr_fd("fillit_file error", 2);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
