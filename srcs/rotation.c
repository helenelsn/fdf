/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:45:50 by Helene            #+#    #+#             */
/*   Updated: 2023/02/09 18:08:26 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double deg_to_rad(double d);

// part du principe que l'axe x est dirige vers l'observateur ; les deux rotations possibles sont alors celles autour des axes y et z

void    z_rotate(t_map *maps, double angle)
{
    int i;
    int j;
    int x;
    int y;

    i = 0;
    while ((maps->map_0)[i])
    {
        j = 0;
        while (j == 0 || (j > 0 && (maps->map_0)[i][j]))
        {
            x = cos(deg_to_rad(angle)) * (maps->map_0)[i][j].x - sin(deg_to_rad(angle)) * (maps->map_0)[i][j].y;
            y = sin(deg_to_rad(angle)) * (maps->map_0)[i][j].x + cos(deg_to_rad(angle)) * (maps->map_0)[i][j].y;
            (maps->map)[i][j].x = x;
            (maps->map)[i][j].y = y;
            j++;
        }
        i++;
    }
       
}

void    y_rotate(t_map *maps, double angle)
{
    int i;
    int j;
    int x;
    int y;

    i = 0;
    while ((maps->map_0)[i])
    {
        j = 0;
        while (j == 0 || (j > 0 && (maps->map_0)[i][j]))
        {
            x = cos(deg_to_rad(angle)) * (maps->map_0)[i][j].x + sin(deg_to_rad(angle)) * (maps->map_0)[i][j].z;
            y = - sin(deg_to_rad(angle)) * (maps->map_0)[i][j].x + cos(deg_to_rad(angle)) * (maps->map_0)[i][j].z;
            (maps->map)[i][j].x = x;
            (maps->map)[i][j].y = y;
            j++;
        }
        i++;
    }
       
}