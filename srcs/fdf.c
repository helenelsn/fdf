/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:01:46 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/30 20:29:15 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    image_pixel_put(t_data *img, int x, int y,unsigned int color)
{
    char *dst;
    dst = img->addr + (img->line_length * y) + (img->bpp / 8 * x);
    *(unsigned int *)dst = color;
}

int main(int argc, char **argv)
{
    // get_next_line
    // pour chaque ligne, split avec les espaces 
    // -> les coordonnees de chaques point obtenus seront inversees (ie aura (y, x, z))
    
    t_data img;
    void *mlx_ptr;
    void *win_ptr;
    t_point **map;
    
    if (argc != 2)
    {
        write(2, "Input Error\n", 12);
        return (-1);
    }
    
    mlx_ptr = mlx_init();
    //win_ptr = mlx_new_window(mlx_ptr, 800, 800, "Fdf\n");
    img.img = mlx_new_image(mlx_ptr, 800, 800);
    img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
    
    
    // ********************** A CODER *********************************
    
    map = get_coordinates(); // cette fonction utilise get next line et malloc chaque ligne de l'input 
    draw_map(mlx_ptr, img, map);

    // *****************************************************************


    //mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 100, 100);
    free_map(&map);
    mlx_destroy_image(mlx_ptr, img.img);
    //mlx_destroy_window(mlx_ptr, win_ptr); // free(win_ptr)
    free(mlx_ptr);
}