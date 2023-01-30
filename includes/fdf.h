/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 02:15:42 by Helene            #+#    #+#             */
/*   Updated: 2023/01/30 21:09:31 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_point
{
	int x;
	int y;
}				t_point;

typedef struct s_point
{
	int x;
	int y;
	int z;
}				t_point3d;

typedef 


void    image_pixel_put(t_data *img, int x, int y, unsigned int color);

t_point3d** 	get_coordinates(void);
void		draw_line(t_data *img, t_point3d u1, t_point3d u2); // u1 = (x1, y1), u2 = (x2, y2)
void		draw_map(void *mlx_ptr, t_data img, t_point3d **map);


#endif