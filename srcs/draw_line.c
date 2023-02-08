/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:56:48 by hlesny            #+#    #+#             */
/*   Updated: 2023/02/06 18:18:08 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int      ft_abs(int x) // abs(x - y)
{
    return ((((x > 0) * 2) - 1) * x);
}

void    image_pixel_put(t_data *img, int x, int y,unsigned int color)
{
    char *dst;

    if (x < 0 || x > 600 || y < 0 || y > 600)    
        return ;
    //printf("img->addr = %s\n", img->addr);
    dst = img->addr + (img->line_length * y) + (x > 0) * (img->bpp / 8 * x); 
    //printf("dst = %s\n", dst);
    *(unsigned int *)dst = color;
}

// int trgb : noir : rgb à 0 ; blanc : rgb à 255
// définir (proportionnellement à z_max et z_min ?) la couleur associée à |z1 - z2|, en accord avec z1 et z2 (et |z|_max ?)
unsigned int compute_color(int z1, int z2)
{
    //unsigned int i;
    (void)z1;
    (void)z2;
    return (0xffffff);
}

static void	    line_numerous_y(t_data *img, t_point3d u1, t_point3d u2)
{
    int x;
    int y;
    unsigned int color;

    if (u2.y < u1.y)
        line_numerous_y(img, u2, u1);
    else
    {
        y = u1.y;
        while (y <= u2.y)
        {
            color = compute_color(u1.z, u2.z);
            x = u1.x + (u2.x - u1.x) * (y - u1.y) / (u2.y - u1.y);
            image_pixel_put(img, x, y, color);
            y++;
        }
    }
}

static void    line_numerous_x(t_data *img, t_point3d u1, t_point3d u2)
{
    int x;
    int y;
    unsigned int color;

    if (u2.x < u1.x)
        line_numerous_x(img, u2, u1);
    else
    {
        x = u1.x;
        while (x <= u2.x)
        {
            color = compute_color(u1.z, u2.z);
            y =  u1.y + (u2.y - u1.y) * (x - u1.x) / (u2.x - u1.x); // pourcentage de perte de precision due a l'arrondi de la division entiere ?
            image_pixel_put(img, x, y, color);
            x++;
        }
    }
}

//void    draw_line(t_data *img, t_point u1, t_point u2, unsigned int color)
void	draw_line(t_data *img, t_point3d u1, t_point3d u2)
{
    if (ft_abs(u1.x - u2.x) >= ft_abs(u1.y - u2.y))
        line_numerous_x(img, u1, u2);
    else // ie pour tout y il existe un unique x, dans [x1, x2] x [y1, y2]
        line_numerous_y(img, u1, u2);
}