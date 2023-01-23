/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 23:02:12 by Helene            #+#    #+#             */
/*   Updated: 2023/01/23 02:29:39 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

static int ft_abs(int x) // abs(x - y)
{
    return ((((x > 0) * 2) - 1) * x);
}

void	draw_line_x(t_data *img, t_point u1, t_point u2)
{
    
}

void	draw_line_y(t_data *img, t_point u1, t_point u2)
{
    if (u2.x >= u1.x)
    {
        //if ((u2.x - u1.x) >= ft_abs(u2.y - u1.y))  
    }
    else
        draw_line(img, u2, u1);
}

void	draw_line(t_data *img, t_point u1, t_point u2) // u1 = (x1, y1), u2 = (x2, y2)
{
    if ((u2.x - u1.x) / (u2.y - u1.y) < 1)
        draw_line_y(img, u1, u2);
    draw_line_x(img, u1, u2);
}