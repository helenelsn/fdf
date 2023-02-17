/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_points.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:05:27 by hlesny            #+#    #+#             */
/*   Updated: 2023/02/13 14:26:22 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    print_map(t_point3d** map);

void    put_points(t_data *data)
{
    int i;
    int j;
    char *dst;

    i = 0;
    j = 0;
    //print_map(map);
    while (data->maps->map[i])
    {
        j = 0;
        while(j == 0 || (j > 0 && data->maps->map[i][j].y != 0))
        {
            //printf("tracage de (%d, %d, %d)\n", data->maps->map[i][j].x, data->maps->map[i][j].y, data->maps->map[i][j].z);
            if (data->maps->map[i][j].x >= 0 && data->maps->map[i][j].y >= 0 && data->maps->map[i][j].x <= X_IMG 
                && data->maps->map[i][j].y <= Y_IMG)
            {
                dst = data->image.addr + (data->image.line_length * data->maps->map[i][j].y) 
                    + (data->maps->map[i][j].x > 0) * (data->image.bpp / 8 * data->maps->map[i][j].x);
                //if (dst <= mlx.image.addr + (mlx.image.line_length * 600) + (mlx.image.bpp / 8 * 600))
                *(unsigned int *)dst = data->maps->map[i][j].color;
            }
            
            //image_pixel_put(mlx.image.img, map[i][j].x, map[i][j].y, 0xffffff);
            j++;
        }
        i++;
    }
}