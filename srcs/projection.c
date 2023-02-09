/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:28:54 by hlesny            #+#    #+#             */
/*   Updated: 2023/02/09 18:35:19 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    print_map(t_point3d** map);

double deg_to_rad(double d)
{
    return (d * (M_PI / 180.0));
}

void    iso(t_point3d ***map, int factor, int y_2d_0, int x_2d_0)
{
    int i;
    int j;
    int x_2d;
    int y_2d;
    double a1;
    double a2;
    double b1;
    double b2;

    i = 0;
    a1 = cos(deg_to_rad(45));
    a2 = sqrt(1 - (a1 * a1));
    b1 = cos(deg_to_rad(35.26));
    b2 = sqrt(1 - (b1 * b1));
    //print_map(*map);
    while ((*map)[i])
    {
        j = 0;
        while (j == 0 || (j > 0 && (*map)[i][j].y != 0))
        {
            x_2d = x_2d_0 + factor * (a1 * (*map)[i][j].x + a2 * (*map)[i][j].y);
            y_2d = y_2d_0 + factor * (b2 * (a2 * (*map)[i][j].x - a1 * (*map)[i][j].y) - b1 * (*map)[i][j].z); // pourquoi doit mettre -b1 ? 
            (*map)[i][j].x = x_2d;
            (*map)[i][j].y = y_2d;
            j++;
        }
        i++;
    }
}