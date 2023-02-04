/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:01:46 by hlesny            #+#    #+#             */
/*   Updated: 2023/02/04 21:44:46 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    image_pixel_put(t_data *img, int x, int y,unsigned int color)
{
    char *dst;
    dst = img->addr + (img->line_length * y) + (img->bpp / 8 * x);
    *(unsigned int *)dst = color;
}

// ne pas oublier de vérifier que le fd passé en ligne de commande est un .fdf ! (comment faire ?)
int main(int argc, char **argv)
{
    // get_next_line
    // pour chaque ligne, split avec les espaces 
    // -> les coordonnees de chaques point obtenus seront inversees (ie aura (y, x, z))
    
    t_mlx mlx;
    t_point3d **map;
    
    if (argc != 2)
    {
        write(2, "Input Error\n", 12);
        return (-1);
    }
    
    mlx.mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 800, 800, "Fdf\n");
    mlx.image->img = mlx_new_image(mlx_ptr, 800, 800);
    mlx.image->addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
    
    
    // ********************** A CODER *********************************
    
    map = get_coordinates(); // cette fonction utilise get next line, ft_split et atoi 
    isometric_proj(&map);
    draw_map(mlx, map, 0, 0);

    // *****************************************************************


    mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 100, 100);
    free_map(&map);
    mlx_destroy_image(mlx_ptr, img.img);
    //mlx_destroy_window(mlx_ptr, win_ptr); // free(win_ptr)
    free(mlx_ptr);
}