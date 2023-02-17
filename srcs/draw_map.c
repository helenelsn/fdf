/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:30:42 by hlesny            #+#    #+#             */
/*   Updated: 2023/02/13 11:56:28 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"  

void    print_map(t_point3d **map);

void	draw_map(t_data *data)
{

    int i;
    int j;

    i = 0;
    j = 0;
    //print_map(map);
    while (data->maps->map[i])
    {
        j = 0;
        while (j == 0 || data->maps->map[i][j].y != 0) // ie tant que l'on n'a pas j > 0 et data->maps->map[i][j].y = 0
        {
            if (data->maps->map[i + 1])
                draw_line(&(data->image), data->maps->map[i][j], data->maps->map[i + 1][j]);
            if (data->maps->map[i][j + 1].y != 0)
                draw_line(&(data->image), data->maps->map[i][j], data->maps->map[i][j + 1]);
            j++;
        }
        i++;
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
}