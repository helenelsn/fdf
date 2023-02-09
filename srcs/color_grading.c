/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_grading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:51:15 by hlesny            #+#    #+#             */
/*   Updated: 2023/02/09 00:00:01 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void    set_color(t_point3d *map, int z_min)
{
    unsigned int y_min; // blue
    int a;

    a = y_min / z_min;
    y_min = 0x4876ff;
    return (y_min + (y_min / z_min) * ((*map).z - z_min));
}

void    get_colors(t_point3d ***map, int z_min)
{
    int i;
    int j;

    i = 0;
    while ((*map)[i])
    {
        j = 0;
        while (j == 0 || (j > 0 && (*map)[i][j].y != 0))
        {
            set_color(&(*map)[i][j], z_min);
            j++;
        }
        i++;
    }
}