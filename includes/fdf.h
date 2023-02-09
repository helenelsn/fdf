/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 02:15:42 by Helene            #+#    #+#             */
/*   Updated: 2023/02/09 18:31:01 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <mlx.h>
#include "get_next_line.h"
#include "key_hook.h"

#define HEXA "0123456789abcdef"

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_mlx 
{
	void *mlx_ptr;
	void *win_ptr;
	t_data image; // t_data *image ou t_data image ? ie pointeur ou non ?
}				t_mlx;

typedef struct s_point3d
{
	int x;
	int y;
	int z;
	unsigned int color;
}				t_point3d;

typedef struct 	s_map
{
	t_point3d **map_0; // coordonnees en 3d
	t_point3d **map; // coordonnees apres projection, ie celle a tracer sur l'image
}				t_map;

// =================== get map datas ===========================
int		ft_strlen(char *str);
char	**ft_split(const char *str, char charset);
void	*ft_calloc(size_t nmemb, size_t size);
long long	ft_atoi(const char *nptr, int *i);
unsigned int	atoi_base(const char *s);
void	get_coordinates(int fd, t_map *maps);

// =================== draw lines ====================

void    put_points(t_mlx mlx, t_point3d **map);

void    get_colors(t_point3d ***map, int z_min);

void    image_pixel_put(t_data *img, int x, int y, unsigned int color);
void	draw_line(t_data *img, t_point3d u1, t_point3d u2); // u1 = (x1, y1), u2 = (x2, y2)
void	draw_map(t_mlx mlx, t_point3d **map);
int     end_of_row(t_point3d p, int j);

// ======== projections et operations matricielles ========

void    iso(t_point3d ***map, int factor, int y_2d_0, int x_2d_0);
void    isometric_proj(t_point3d ***map);
void    rotate(t_point3d ***map);
void    translate(t_point3d ***map, int shift, int x_translate);

// =================== hooks functions ============

int	close2(void *mlx_ptr);

#endif