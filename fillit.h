/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 17:49:30 by ybecret           #+#    #+#             */
/*   Updated: 2017/02/18 15:09:06 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_h
# define FILLIT_h

# define BUFF_SIZE 545

typedef struct	s_list
{
	char			tetriminos[17];
}					t_list;

typedef struct	s_tetris
{
	char			piece[17];
	int				index;
}					t_tetris;

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	first_check(char *buff);
void	check_errors(int i);

int	fillit(int fd);
int	fill_tetris(t_tetris *tetris, char *buff, int nb_piece);
int     nb_tetriminos(char *buff);
t_list* fill_valid(void);
int     test_tetris(t_tetris *tetris, int nb_tetriminos);

size_t	ft_strlen(char *s);
void    ft_putstr_fd(char *s, int fd);
char    *ft_strnew(size_t size);
char	*ft_strcpy(char *dest, const char *src);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_sqrt(int nb);

#endif
