/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 17:49:30 by ybecret           #+#    #+#             */
/*   Updated: 2017/04/20 17:28:46 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 545
# define POSX	pos_spe	% size
# define POSY 	pos_spe / size

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_valid
{
	char	tetriminos[17];
}				t_valid;

typedef struct	s_tetris
{
	char	piece[17];
	int		position[2][4];
	int		pos_spe;
	int		nb_piece;
	int		size;
}				t_tetris;

void			first_check(char *buff);
void			check_errors(int i);

int				fillit(int fd);
int				fill_tetris(t_tetris *tetris, char *buff, int nb_piece, int j);
int				nb_tetriminos(char *buff);
char			*tp_theleft(char *piece, int i, int j, int test);
char			*ft_replace(char *piece, int i, int j, int test);
t_valid			*fill_valid(void);
int				test_tetris(t_tetris *tetris, int nb_tetriminos);

void			fill_pos(t_tetris *tetris, int nb_piece);
void			init_pos(t_tetris *tetris, int index);

int				ft_sqrt(int nb);
int				fill_grid(t_tetris *tetris, int nb_piece);
void			set_grid (char **grid, int size);
void			print_grid(char **grid, int size, int *cnt);
void			free_grid(char **grid, int size);
void			init_grid(char **grid, int size);

int				test_pos(char **grid, t_tetris *tetris, int index, \
				int pos_spe);
void			place_piece(char **grid, t_tetris *tetris, int index, \
				int pos_spe);
void			delete_piece(char **grid, t_tetris *tetris, int index, \
				int size);
int				backtracking(t_tetris *tetris, char **grid, int size, \
				int index);

size_t			ft_strlen(char *s);
void			ft_putstr_fd(char *s, int fd);
char			*ft_strnew(size_t size);
char			*ft_strcpy(char *dest, const char *src);
int				ft_strcmp(const char *s1, const char *s2);

#endif
