/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 23:02:12 by Helene            #+#    #+#             */
/*   Updated: 2023/02/05 19:27:03 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

static int ft_abs(int x) // abs(x - y)
{
    return ((((x > 0) * 2) - 1) * x);
}

void	line_numerous_y(t_data *img, t_point3d u1, t_point3d u2, unsigned int color)
{
    int x;
    int y;

    if (u2.y < u1.y)
        line_numerous_y(img, u2, u1, color);
    else
    {
        y = u1.y;
        while (y <= u2.y)
        {
            x = u1.x + (u2.x - u1.x) * (y - u1.y) / (u2.y - u1.y);
            image_pixel_put(img, x, y, color);
            y++;
        }
    }
}

void    line_numerous_x(t_data *img, t_point3d u1, t_point3d u2, unsigned int color)
{
    int x;
    int y;

    if (u2.x < u1.x)
        line_numerous_x(img, u2, u1, color);
    else
    {
        x = u1.x;
        while (x <= u2.x)
        {
            y =  u1.y + (u2.y - u1.y) * (x - u1.x) / (u2.x - u1.x); // pourcentage de perte de precision due a l'arrondi de la division entiere ?
            image_pixel_put(img, x, y, color);
            x++;
        }
    }
}

void    draw_line(t_data *img, t_point3d u1, t_point3d u2, unsigned int color)
{
    if (ft_abs(u1.x - u2.x) >= ft_abs(u1.y - u2.y))
        line_numerous_x(img, u1, u2, color);
    else // ie pour tout y il existe un unique x, dans [x1, x2] x [y1, y2]
        line_numerous_y(img, u1, u2, color);
}