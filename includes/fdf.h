/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 02:15:42 by Helene            #+#    #+#             */
/*   Updated: 2023/02/02 18:16:04 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <math.h>

typedef struct	s_data 
{
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
	int z;
}				t_point3d;

typedef struct s_z 
{
	int z_min;
	int z_max;
}				t_z;

typedef struct s_mlx 
{
	void *mlx_ptr;
	void *win_ptr;
	t_data *image; // t_data *image ou t_data image ? ie pointeur ou non ?
}				t_mlx;

typedef t_point3d** map;

char	*get_next_line(int fd);
char	**ft_split(const char *str, char charset);
void	*ft_calloc(size_t nmemb, size_t size);
long long	ft_atoi(const char *nptr, int *j);
void    isometric_proj(t_point3d ***map);

void    image_pixel_put(t_data *img, int x, int y, unsigned int color);

map 	get_coordinates(int fd);
void	draw_line(t_data *img, t_point3d u1, t_point3d u2); // u1 = (x1, y1), u2 = (x2, y2)
void	draw_map(t_mlx mlx, t_point3d **map, int i, int j);


#endif