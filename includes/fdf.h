/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 02:15:42 by Helene            #+#    #+#             */
/*   Updated: 2023/02/15 15:59:35 by hlesny           ###   ########.fr       */
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

# define X_WIN	2000
# define Y_WIN	1800
# define X_IMG	2000
# define Y_IMG	1800

# define ISO 	1
# define PARA	0
# define CONIC	0
// 0001 (1) : isometrique
// 0010 (2) : parallele
// 0100 (4) : conique
# define PROJ	0001 // determiner la projection : (PROJ & 1111)

// pour la projection isometrique
# define FACTOR 1
# define X_0 	500
# define Y_0 	300

// rotation
# define R_ANGLE	10 

// translation 
# define TR_SHIFT	40

// zoom 
# define ZOOM_COEF	2

typedef struct	s_image 
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_image;

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

typedef struct 	s_data
{
	void *mlx_ptr;
	void *win_ptr;
	t_image image;
	t_map *maps;
}				t_data;

// =================== get map datas ===========================
int		ft_strlen(char *str);
char	**ft_split(const char *str, char charset);
void	*ft_calloc(size_t nmemb, size_t size);
long long	ft_atoi(const char *nptr, int *i);
unsigned int	atoi_base(const char *s);
void	get_coordinates(int fd, t_map *maps);

// =================== draw lines ====================

void    put_points(t_data *data);

void    get_colors(t_point3d ***map, int z_min);

void    image_pixel_put(t_image *img, int x, int y, unsigned int color);
void	draw_line(t_image *img, t_point3d u1, t_point3d u2); // u1 = (x1, y1), u2 = (x2, y2)
void	draw_map(t_data *data);
int     end_of_row(t_point3d p, int j);

// ======== projections et operations matricielles ========

void    iso(t_map *maps);
void    rotate(t_data *data, int keycode);
void    translate(t_data *data, int keycode);

// =================== hooks functions ============

int	key_press(int keycode, t_data *data);
int	close2(void *mlx_ptr);

#endif