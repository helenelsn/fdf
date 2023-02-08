/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:01:46 by hlesny            #+#    #+#             */
/*   Updated: 2023/02/08 00:05:19 by hlesny           ###   ########.fr       */
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
            printf("map[%d][%d] = (%d, %d, %d)\n", i, j, map[i][j].x, map[i][j].y, map[i][j].z);
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
    t_point3d **map;
/*
    if (argc != 2 || (fd = open(argv[1], O_RDONLY) < 0))
    {
        write(2, "Input Error\n", 12);
        return (-1);
    }
*/      
    
fd = open("42.fdf", O_RDONLY);

    mlx.mlx_ptr = mlx_init();
    mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 800, 800, "Fdf");
    mlx.image.img = mlx_new_image(mlx.mlx_ptr, 600, 600);
    mlx.image.addr = mlx_get_data_addr(mlx.image.img, &(mlx.image.bpp), 
                        &(mlx.image.line_length), &(mlx.image.endian));
    
///*
    // ********************** A CODER *********************************
    
    map = get_coordinates(fd);
    print_map(map);
    iso(&map, 5, 200, 200);
    //isometric_proj(&map);
    //printf("\n\n\n\n\n\n\n");
    //print_map(map);
    put_points(mlx, map);
    //draw_map(mlx, map);
   

    // *****************************************************************
//*/
  
    mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.image.img, 100, 100);

    mlx_hook(mlx.win_ptr, 33, 1L<<17, close2, mlx.mlx_ptr);
    mlx_loop(mlx.mlx_ptr);
    
    
    //free_map(&map);
    //mlx_destroy_image(mlx.mlx_ptr, mlx.image.img);
    //mlx_destroy_window(mlx.mlx_ptr, mlx.win_ptr); // free(win_ptr)
    //free(mlx.mlx_ptr);
}