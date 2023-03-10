/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 22:38:36 by Helene            #+#    #+#             */
/*   Updated: 2023/02/05 19:26:29 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

#include <math.h>

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_point3d
{
	int x;
	int y;
	int z;
}				t_point3d;

void	draw_line(t_data *img, t_point3d u1, t_point3d u2, unsigned int color); // u1 = (x1, y1), u2 = (x2, y2)



#endif