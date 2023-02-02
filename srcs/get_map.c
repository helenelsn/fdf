/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:30:17 by hlesny            #+#    #+#             */
/*   Updated: 2023/02/02 15:21:18 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static void fill_row(t_point3d **map, char *row, int column)
{
    static int row_length; // initialise a 0 par defaut dans le cas d'une static
    int i;
    char s;

    s = ft_split(row, ' ');
    i = -1;
    if (!row_length)
    {
        while (s[row_length])
            row_length++;
    }
    *map = ft_calloc(sizeof(t_point3d), row_length + 1);
    while (s[++i])
        set_point(&(*map)[i], i, column, ft_atoi(s[i]));
    // (*map)[i] = 
    // quel est l'equivalent de NULL pour t_point3d pour le dernier element de map[i] ? 
    // pour savoir quand est a la fin d'une ligne lors du parsing qd va tracer la map
}

static t_point3d **fill_map(char *input)
{
    int i;
    char **m;
    t_point3d **map;
    
    i = 0;
    m = ft_split(input, '\n');
    while (m[i])
        i++;
    map = ft_calloc(sizeof(t_point3d *), i + 1); // +1 car rajoute NULL a la fin, + simple pour parser apres
    i = -1;
    while (m[++i])
        fill_row(&map[i], m[i], i);
    map[i] = NULL;
    // il faut encore mettre la map dans le bon ordre (avecle parsing fait ici, les x t les y sont echanges)
    free_tab(&m);
}


t_point3d **get_coordinates(int fd)
{
    char *row;
    char *input;
    
    row_length = 0;
    row = get_next_line(fd);
    input = NULL;
    while (row)
    {
        ft_strncat(input, row, 0);
        free(row);
        row = get_next_line(fd);
    }
    
    return (fill_map(input));
}