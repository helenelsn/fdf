/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 01:33:25 by hlesny            #+#    #+#             */
/*   Updated: 2023/02/13 21:57:41 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    translate(t_data *data, int keycode) // !!! : rajouter une securite en plus qui fait qu'on ne peut plus shift la figure si celle-ci est amenee a depasser le cadre de l'image
{
    int i;
    int j;

    i = 0;
    while ((data->maps->map)[i])
    {
        j = 0;
        while (j == 0 || (j > 0 && (data->maps->map)[i][j].y != 0))
        {
            if (keycode == KEY_R || keycode == KEY_L)
            {
                (data->maps->map_0)[i][j].x += ((keycode == KEY_R) * 2 - 1) * TR_SHIFT;
                (data->maps->map)[i][j].x += ((keycode == KEY_R) * 2 - 1) * TR_SHIFT;   
            }
            else
            {
                (data->maps->map_0)[i][j].y += ((keycode == KEY_D) * 2 - 1) * TR_SHIFT;
                (data->maps->map)[i][j].y += ((keycode == KEY_D) * 2 - 1) * TR_SHIFT;   
            }
            j++;
        }
        i++;
    }
    draw_map(data);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.img, 100, 100);
}
