/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:28:54 by hlesny            #+#    #+#             */
/*   Updated: 2023/02/05 18:23:47 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void    transform_iso(t_point3d *map)
{
    double a;
    int x;
    int y;

    a = 0.40825; // ie 1/sqrt(6) avec 5 chiffres significatifs
    // aplique les matrices de rotation aux coordonnees de base
    x = a * (sqrt(3) * map->x + -sqrt(3) * map->z);
    y = a * (map->x + 2 * map->y + map->z);
    map->x = x;
    map->y = y; // s'en blc de  mettre z a 0, l'utilise pas pour tracer les lignes apres (mais en a besoin pr le gradient de couleurs)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
}

void    isometric_proj(t_point3d ***map)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while ((*map)[i])
    {
        while (!end_of_row((*map)[i][j], j))
        {
            transform_iso(&(*map)[i][j]); //bonne syntaxe ? ou est-ce que & et * s'annulent ? 
            j++;
        }
        i++;
    }
}