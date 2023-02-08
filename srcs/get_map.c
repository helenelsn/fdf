/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:30:17 by hlesny            #+#    #+#             */
/*   Updated: 2023/02/07 22:48:19 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    print_map(t_point3d** map);

static void free_tab(char ***r)
{
    int i;
    
    i = 0;
    while ((*r)[i])
    {
        free((*r)[i]);
        i++;
    }
    free(*r);
    *r = NULL; // utile ?
}

void    set_point(t_point3d *u, int x, int y, int z)
{
    u->x = x;
    u->y = y;
    u->z = z;
}

static void fill_row(t_point3d **map, char *row, int j)
{
    // static pour éviter de devoir calculer à chaque appel à fill_row le nombre de colonnes à malloc,
    // car part du principe que la map sera "homogène" 
    // ie (toutes les lignes auront le meme nombre de colonnes et vice versa)
    static int row_length; // initialise a 0 par defaut dans le cas d'une static
    int i;
    int x;
    char **s;

    s = ft_split(row, ' ');
    i = -1;
    if (!row_length) // ie si c'est le premier appel à fill_row
    {
        while (s[row_length])
            row_length++;
    }
    x = j * row_length;
    *map = ft_calloc(sizeof(t_point3d), row_length + 1);
    while (s[++i])
    {
        //printf("ligne %d, colonne %d, z = %s\n", j, i, s[i]);
        set_point(&(*map)[i], x, i * row_length, ft_atoi(s[i]));
    }
        
    set_point(&(*map)[i], 0, 0, 0); // histoire de "null-terminate" les map[i] afin de faciliter le parsing
}

static t_point3d **fill_map(char *input, int col_length)
{
    int i;
    char **m;
    t_point3d **map;
    
    i = -1;
    
    m = ft_split(input, '\n'); 
    map = ft_calloc(sizeof(t_point3d *), col_length + 1); 

    while (m[++i])
        fill_row(&map[i], m[i], i);
    map[i] = NULL;
    
    //print_map(map);
    free_tab(&m);
    return (map);
}


t_point3d **get_coordinates(int fd)
{
    char *row; // buffer utilisé pour lire chaque ligne du fichier .fdf
    char *input; // concatène les lignes de l'input, et obtient ainsi un char* correspondant à l'entièreté de la map
    int col_length;
    
    row = get_next_line(fd);
    col_length = 0;
    input = NULL;
    while (row)
    {
        col_length++;
        input = ft_strncat(input, row, 0);
        free(row);
        row = get_next_line(fd);
    }
    return (fill_map(input, col_length));
}