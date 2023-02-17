/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:01:46 by hlesny            #+#    #+#             */
/*   Updated: 2023/02/13 22:21:42 by hlesny           ###   ########.fr       */
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

void    initialise_data(t_data *data)
{
    data->maps = malloc(sizeof(t_map *));
}

// vérifier que le fd passé en ligne de commande est un .fdf ? (comment faire ?)
int main(int argc, char **argv)
{
    // get_next_line
    // pour chaque ligne, split avec les espaces 
    // -> les coordonnees de chaques point obtenus seront inversees (ie aura (y, x, z))
    
    int fd;
    t_data data;
    initialise_data(&data); // ?
    
    if (argc != 2)
    {
        write(2, "Input Error\n", 12);
        return (-1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (-1);

    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, X_WIN, Y_WIN, "Fdf");
    data.image.img = mlx_new_image(data.mlx_ptr, X_IMG, Y_IMG);
    data.image.addr = mlx_get_data_addr(data.image.img, &(data.image.bpp), 
                        &(data.image.line_length), &(data.image.endian));
    
///*
    // ********************** A CODER *********************************
    
    get_coordinates(fd, data.maps);
    iso(data.maps); // (&data.maps->map) ? 
    //print_map(maps.map);
    //put_points(mlx, map);
    
    draw_map(&data);
   

    // *****************************************************************
//*/
  
    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.image.img, 100, 100);

    mlx_hook(data.win_ptr, 2, 1L<<0, key_press, &data);
    //mlx_key_hook(data.win_ptr, key_press, data.mlx_ptr);
    mlx_hook(data.win_ptr, 33, 1L<<17, close2, data.mlx_ptr);
    mlx_loop(data.mlx_ptr);
    
    
    //free_map(&map);
    //mlx_destroy_image(mlx.mlx_ptr, mlx.image.img);
    //mlx_destroy_window(mlx.mlx_ptr, mlx.win_ptr); // free(win_ptr)
    //free(mlx.mlx_ptr);
}