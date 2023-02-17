/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 01:40:15 by hlesny            #+#    #+#             */
/*   Updated: 2023/02/13 22:37:53 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    print_map(t_point3d** map);

void    zoom(t_data *data, int keycode) // a appliquer apres avoir transforme en coord iso
{
    int i;
    int j;

    i = 0;
    // print_map(data->maps->map_0);
    // printf("\n\n\n");
    // print_map(data->maps->map_0);
    // printf("\n\n\n\n\n\n\n\n");
    while ((data->maps->map)[i])
    {
        j = 0;
        while (j == 0 || (j > 0 && (data->maps->map)[i][j].y != 0))
        {
            if (keycode == KEY_I) // zoom in
            {
                (data->maps->map_0)[i][j].x *= ZOOM_COEF;
                (data->maps->map_0)[i][j].y *= ZOOM_COEF;
                (data->maps->map)[i][j].x *= ZOOM_COEF;
                (data->maps->map)[i][j].y *= ZOOM_COEF;
            }   
            else
            {
                (data->maps->map_0)[i][j].x /= ZOOM_COEF;
                (data->maps->map_0)[i][j].y /= ZOOM_COEF;
                (data->maps->map)[i][j].x /= ZOOM_COEF;
                (data->maps->map)[i][j].y /= ZOOM_COEF;
            }
            j++;
        }
        i++;
    }
    // print_map(data->maps->map_0);
    // printf("\n\n\n");
    //print_map(data->maps->map_0);
    draw_map(data);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.img, 100, 100);
}