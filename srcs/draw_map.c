/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:30:42 by hlesny            #+#    #+#             */
/*   Updated: 2023/02/04 21:15:42 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"                                  

void		draw_map(t_mlx mlx, t_point3d **map, int i, int j)
{
    if (map[i + 1] && map[i + 1][j])
    {
        draw_line(mlx.mlx_ptr, map[i][j], map[i + 1][j]);
        draw_map(mlx, map, i + 1, j);
    }
    if (map[i][j + 1])
    {
        draw_line(mlx.mlx_ptr, map[i][j], map[i][j + 1]);
        draw_map(mlx, map, i, j + 1);
    }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
}