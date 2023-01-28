/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:01:46 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/28 21:09:58 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    image_pixel_put(t_data *img, int x, int y,unsigned int color)
{
    char *dst;
    dst = img->addr + (img->line_length * y) + (img->bpp / 8 * x);
    *(unsigned int *)dst = color;
}