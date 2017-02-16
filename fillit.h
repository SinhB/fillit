/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 17:49:30 by ybecret           #+#    #+#             */
/*   Updated: 2017/02/16 16:59:32 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_h
# define FILLIT_h

# define BUFF_SIZE 545

# typedef struct	s_list
{
	char			tetriminos[16];
}					t_list;

# typedef struct	s_tetris
{
	char			piece[16];
	int				index;
}					t_tetris;

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
