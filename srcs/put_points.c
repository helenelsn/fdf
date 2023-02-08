/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:05:27 by hlesny            #+#    #+#             */
/*   Updated: 2023/02/08 00:07:43 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    print_map(t_point3d** map);

void    put_points(t_mlx mlx, t_point3d **map)
{
    int i;
    int j;
    char *dst;

    i = 0;
    j = 0;
    //print_map(map);
    while (map[i])
    {
        j = 0;
        while(j == 0 || (j > 0 && map[i][j].y != 0))
        {
            //printf("tracage de (%d, %d, %d)\n", map[i][j].x, map[i][j].y, map[i][j].z);
            dst = mlx.image.addr + (mlx.image.line_length * map[i][j].y) 
                + (map[i][j].x > 0) * (mlx.image.bpp / 8 * map[i][j].x);
            if (dst > mlx.image.addr + (mlx.image.line_length * 600) + (mlx.image.bpp / 8 * 600))
                return ;
            *(unsigned int *)dst = 0xffffff;
            //image_pixel_put(mlx.image.img, map[i][j].x, map[i][j].y, 0xffffff);
            j++;
        }
        i++;
    }
}