/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 22:38:36 by Helene            #+#    #+#             */
/*   Updated: 2023/01/23 02:16:32 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

#include <math.h>
#include "fdf.h"

typedef struct s_data
{
	void *img_ptr;
	void *data;
	int bpp;
	int line_size;
	int endian;
}				t_data;

typedef struct s_point
{
	int x;
	int y;
}				t_point;

void	draw_line(t_data *img, t_point u1, t_point u2); // u1 = (x1, y1), u2 = (x2, y2)



#endif