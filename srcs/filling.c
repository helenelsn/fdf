/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 23:35:42 by Helene            #+#    #+#             */
/*   Updated: 2023/01/22 23:45:36 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filling.h"

unsigned int    get_pixelcolor_from_image(t_data *img, int x, int y) // avec (x, y) les coordonnées du pixel
{
    
}

int		get_pixelcolor(t_xvar *xvar, int color)
{
  XColor	xc;

  if (xvar->depth>=24)
    return (color);
  xc.red = (color>>8)&0xFF00;
  xc.green = color&0xFF00;
  xc.blue = (color<<8)&0xFF00;
  xc.pixel = ((xc.red>>(16-xvar->decrgb[1]))<<xvar->decrgb[0])+
    ((xc.green>>(16-xvar->decrgb[3]))<<xvar->decrgb[2])+
    ((xc.blue>>(16-xvar->decrgb[5]))<<xvar->decrgb[4]);
  return (xc.pixel);
}