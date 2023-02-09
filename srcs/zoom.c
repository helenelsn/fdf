/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 01:40:15 by hlesny            #+#    #+#             */
/*   Updated: 2023/02/09 16:42:03 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    zoom(t_point3d ***map, int coef, int zoom_in) // a appliquer apres avoir transforme en coord iso
{
    int i;
    int j;

    i = 0;
    while ((*map)[i])
    {
        j = 0;
        while (j == 0 || (j > 0 && (*map)[i][j].y != 0))
        {
            if (zoom_in)
            {
                (*map)[i][j].x *= coef;
                (*map)[i][j].y *= coef;
            }   
            else
            {
                (*map)[i][j].x /= coef;
                (*map)[i][j].y /= coef;
            }
            j++;
        }
        i++;
    }
}