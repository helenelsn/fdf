/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:30:42 by hlesny            #+#    #+#             */
/*   Updated: 2023/02/05 22:18:20 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"  

int     end_of_row(t_point3d p, int y)
{
    return (y > 0 && p.y == 0);   
}

void	draw_map(t_mlx mlx, t_point3d **map)
{
/*
    if (map[i + 1])
    {
        //printf("map[%d][%d] = (%d, %d, %d)\n", i + 1, j, map[i+1][j].x, map[i+1][j].y, map[i+1][j].z);
        printf("trace de (%d, %d) a (%d, %d)\n ", i, j, i + 1, j);
        //map[i + 1][j].x_done = 1;
        draw_line(&(mlx.image), map[i][j], map[i + 1][j]);
    }
    //printf("map[%d][%d] = (%d, %d, %d)\n\n", i, j+1, map[i][j+1].x, map[i][j+1].y, map[i][j+1].z);
    if ((j + 1 > 0) && (map[i][j + 1].y != 0))
    {
        printf("trace de (%d, %d) a (%d, %d)\n", i, j, i, j + 1);
        //map[i][j + 1].y_done = 1;
        draw_line(&(mlx.image), map[i][j], map[i][j + 1]);
    }    
    if (map[i + 1])   
        draw_map(mlx, map, i + 1, j);
    if ((j + 1 > 0) && (map[i][j + 1].y != 0))
        draw_map(mlx, map, i, j + 1);         
*/

    int i;
    int j;

    i = 0;
    j = 0;
    while (map[i])
    {
        j = 0;
        while (j == 0 || map[i][j].y != 0) // ie tant que l'on n'a pas j > 0 et map[i][j].y = 0
        {
            if (map[i + 1])
                draw_line(&(mlx.image), map[i][j], map[i + 1][j]);
            if (map[i][j + 1].y != 0)
                draw_line(&(mlx.image), map[i][j], map[i][j + 1]);
            j++;
        }
        i++;
    }
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
}