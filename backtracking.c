/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 19:27:13 by ybecret           #+#    #+#             */
/*   Updated: 2017/03/30 18:03:44 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     test_pos(char **grid, t_tetris *tetris, int index, int pos_spe, int size)
{
        int x;
        int y;
        int cnt;

        cnt = 0;
        printf("posX : %d\n", posX);
        printf("posY : %d\n", posY);
        while (cnt < 4)
        {
                x = tetris[index].position[0][cnt] + posX;
                y = tetris[index].position[1][cnt] + posY;
                printf("grid: %c\n", grid[y][x]);
                printf("x: %d\n", x);
                printf("y: %d\n", y);
                if (!grid[y][x])
                        return (1);
                if (grid[y][x] == '.')
                        cnt++;
                else
                        return (1);
        }
        return (0);
}

void     place_piece(char **grid, t_tetris *tetris, int index, int pos_spe, int size)
{
        int x;
        int y;
        int cnt;

        cnt = 0;
        while (cnt < 4)
        {
                x = tetris[index].position[0][cnt] + posX;
                y = tetris[index].position[1][cnt] + posY;
                grid[y][x] = index + 65;
                cnt++;
        }
}

void    delete_piece(char **grid, t_tetris *tetris, int index, int pos_spe, int size)
{
        int x;
        int y;
        int cnt;

        cnt = 0;
        while (cnt < 4)
        {
                x = tetris[index].position[0][cnt] + posX;
                y = tetris[index].position[1][cnt] + posY;
                grid[y][x] = '.';
                cnt++;
        }
}

int     backtracking(t_tetris *tetris, char **grid, int size, int nb_piece, int pos_spe, int index)
{
  //      int index;
        static int start;

    //    index = 0;
        while ((pos_spe <= (size * size)))
        {
                printf("index : %d\n", index);
                printf("pos_spe : %d\n", pos_spe);
                if ((pos_spe == (size * size)) && ((index + 1 != nb_piece)))
                {
                        free_grid(grid, size);
                        if (!(grid = (char**)malloc(sizeof(char*) * size)))
                                check_errors(0);
                        set_grid(grid, size);
                        backtracking(tetris, grid, size, nb_piece, (start + 1), 0);
                }
                if (test_pos(grid, tetris, index, pos_spe, size) == 0)
                {
                        printf("test_pos = 0\n");
                        place_piece(grid, tetris, index, pos_spe, size);
                        if ((index + 1) != nb_piece)
                                backtracking(tetris, grid, size, nb_piece, 0, (index + 1));
                        else if ((index + 1) == nb_piece)
                        {
                                print_grid(grid, size);
                                return (1);
                        }
                        return (1);
                }
                pos_spe++;
        }
        printf("blabala\n");
        return (0);
}
