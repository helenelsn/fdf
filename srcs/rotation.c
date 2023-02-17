/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:45:50 by Helene            #+#    #+#             */
/*   Updated: 2023/02/15 16:00:33 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double deg_to_rad(double d);

// part du principe que l'axe x est dirige vers l'observateur ; les deux rotations possibles sont alors celles autour des axes y et z
/*
void    z_rotate(t_data *data, double angle) // envoie un angle en degre
{
    int i;
    int j;
    int x;
    int y;

    i = 0;
    while ((data->maps->map_0)[i])
    {
        j = 0;
        while (j == 0 || (data->maps->map_0)[i][j].y != 0)
        {
            x = cos(deg_to_rad(angle)) * (data->maps->map_0)[i][j].x - sin(deg_to_rad(angle)) * (data->maps->map_0)[i][j].y;
            y = sin(deg_to_rad(angle)) * (data->maps->map_0)[i][j].x + cos(deg_to_rad(angle)) * (data->maps->map_0)[i][j].y;
            (data->maps->map_0)[i][j].x = x;
            (data->maps->map_0)[i][j].y = y;
            j++;
        }
        i++;
    }  
}
*/



void    z_rotate(t_data *data, double angle)
{
    int i;
    int j;
    int x;
    int y;

    i = 0;
    while ((data->maps->map_0)[i])
    {
        j = 0;
        while (j == 0 || (data->maps->map_0)[i][j].y != 0)
        {
            x = cos(deg_to_rad(angle)) * (data->maps->map_0)[i][j].x - sin(deg_to_rad(angle)) * (data->maps->map_0)[i][j].y;
            y = sin(deg_to_rad(angle)) * (data->maps->map_0)[i][j].x + cos(deg_to_rad(angle)) * (data->maps->map_0)[i][j].y;
            (data->maps->map_0)[i][j].x = x;
            (data->maps->map_0)[i][j].y = y;
            j++;
        }
        i++;
    }  
}

void    y_rotate(t_data *data, double angle) // envoie un angle en degre
{
    int i;
    int j;
    int x;
    int y;

    i = 0;
    while ((data->maps->map_0)[i])
    {
        j = 0;
        while (j == 0 || (j > 0 && (data->maps->map_0)[i][j].y != 0))
        {
            x = cos(deg_to_rad(angle)) * (data->maps->map)[i][j].x + sin(deg_to_rad(angle)) * (data->maps->map)[i][j].z;
            y = - sin(deg_to_rad(angle)) * (data->maps->map)[i][j].x + cos(deg_to_rad(angle)) * (data->maps->map)[i][j].z;
            (data->maps->map)[i][j].x = x;
            (data->maps->map)[i][j].y = y;
            j++;
        }
        i++;
    }
}

//  n'apliquer lq rotation qu'autour de l'axe z

void    rotate(t_data *data, int keycode)
{
    if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
        z_rotate(data, ((keycode == KEY_LEFT) * 2 - 1) * ANGLE);
    else
        y_rotate(data, ((keycode == KEY_UP) * 2 - 1) * ANGLE);
    //iso(data->maps);
    draw_map(data);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.img, 100, 100);
}