/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:01:46 by hlesny            #+#    #+#             */
/*   Updated: 2023/02/12 16:58:17 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    print_map(t_point3d** map)
{
    int i = 0;
    int j;
    
    while (map[i])
    {
        j = 0;
        while (j == 0 || (j > 0 && map[i][j].y != 0))
        {
            printf("map[%d][%d] = (%d, %d, %d), color = %u\n", i, j, map[i][j].x, map[i][j].y, map[i][j].z, map[i][j].color);
            j++;
        }
        i++;
    }
    printf("\n\n");
}

// vérifier que le fd passé en ligne de commande est un .fdf ? (comment faire ?)
int main(int argc, char **argv)
{
    // get_next_line
    // pour chaque ligne, split avec les espaces 
    // -> les coordonnees de chaques point obtenus seront inversees (ie aura (y, x, z))
    
    int fd;
    t_mlx mlx;
    t_map maps;
    
    if (argc != 2)
    {
        write(2, "Input Error\n", 12);
        return (-1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (-1);

    mlx.mlx_ptr = mlx_init();
    mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 2000, 1800, "Fdf");
    mlx.image.img = mlx_new_image(mlx.mlx_ptr, 2000, 1800);
    mlx.image.addr = mlx_get_data_addr(mlx.image.img, &(mlx.image.bpp), 
                        &(mlx.image.line_length), &(mlx.image.endian));
    
///*
    // ********************** A CODER *********************************
    
    get_coordinates(fd, &maps);
    iso(&maps.map, FACTOR, X_0, Y_0);
    //print_map(maps.map);
    //put_points(mlx, map);
    
    draw_map(mlx, maps.map);
   

    // *****************************************************************
//*/
  
    mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.image.img, 100, 100);

    mlx_hook(mlx.win_ptr, 2, 1L<<0, key_press, mlx.mlx_ptr);
    //mlx_key_hook(mlx.win_ptr, key_press, mlx.mlx_ptr);
    mlx_hook(mlx.win_ptr, 33, 1L<<17, close2, mlx.mlx_ptr);
    mlx_loop(mlx.mlx_ptr);
    
    
    //free_map(&map);
    //mlx_destroy_image(mlx.mlx_ptr, mlx.image.img);
    //mlx_destroy_window(mlx.mlx_ptr, mlx.win_ptr); // free(win_ptr)
    //free(mlx.mlx_ptr);
}