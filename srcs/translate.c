/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 01:33:25 by hlesny            #+#    #+#             */
/*   Updated: 2023/02/09 16:42:48 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    translate(t_point3d ***map, int shift, int x_translate) // !!! : rajouter une securite en plus qui fait qu'on ne peut plus shift la figure si celle-ci est amenee a depasser le cadre de l'image
{
    int i;
    int j;

    i = 0;
    while ((*map)[i])
    {
        j = 0;
        while (j == 0 || (j > 0 && (*map)[i][j].y != 0))
        {
            if (x_translate)
                (*map)[i][j].x += shift;
            else
                (*map)[i][j].y += shift;
            j++;
        }
        i++;
    }
}

