/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:28:54 by hlesny            #+#    #+#             */
/*   Updated: 2023/02/08 19:05:50 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    print_map(t_point3d** map);

double deg_to_rad(double d)
{
    return (d * (M_PI / 180.0));
}

static void    transform_iso(t_point3d *map)
{
    double alpha;
    double beta;
    int x;
    int y;

    alpha = deg_to_rad(30);
    beta = deg_to_rad(45);
    x = map->x * cos(beta) - map->z * sin(beta);
    y = map->x * sin(alpha) * sin(beta) + map->y * cos(alpha) + map->z * sin(alpha) * cos(beta);
    //printf("x = %d, x_iso = %d, y = %d, y_iso = %d\n", map->x, x, map->y, y);
    map->x = x;
    map->y = y; // s'en blc de  mettre z a 0, l'utilise pas pour tracer les lignes apres (mais en a besoin pr le gradient de couleurs)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
}

void    isometric_proj(t_point3d ***map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    //printf("\n\n\n dans la fonction de projection, avant :\n");
    //print_map(*map);
    while ((*map)[i])
    {
        j = 0;
        while (j == 0 || (j > 0 && (*map)[i][j].y != 0))
        {
            //printf("map[%d][%d] = (%d, %d, %d)\n", i, j, (*map)[i][j].x, (*map)[i][j].y, (*map)[i][j].z);
            transform_iso(&(*map)[i][j]); //bonne syntaxe ? ou est-ce que & et * s'annulent ? 
            //printf("map[%d][%d] = (%d, %d, %d)\n", i, j, (*map)[i][j].x, (*map)[i][j].y, (*map)[i][j].z);
            j++;
        }
        i++;
    }
    //printf("\n\n\n dans la fonction de projection, apres :\n");
    //print_map(*map);
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