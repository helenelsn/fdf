/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:51:40 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/30 20:54:49 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "shapes.h"
#include "fdf.h"


/*
Évènement clavier :     gere_key(int keycode, void *param);
                        mlx_key_hook(void *win_ptr, int (*f()), void *param);

Évènement souris :      gere_mouse(int button, int x, int y, void *param);
                        mlx_mouse_hook(void *win_ptr, int (*f()), void *param);

Évènement expose (lorsqu'une partie ou la totalité de la fenêtre doit être réaffichée) :
                        gere_expose(void *param);
                        mlx_expose_hook(void *win_ptr, int (*f()), void *param);

Ensuite (indispensable) : 
                        mlx_loop(mlx_ptr);

Le(s) octet(s) en mémoire ne correspond(ent) pas forcément a/aux octet(s) d'une couleur exprimée en RGB :
Il existe une fonction de transfert entre une couleur définie par ses composants RGB et le(s) 
octet(s) qui seront stockés en mémoire vidéo (ou dans une image) :
                        
                        unsigned int mlx_get_color_value(void *mlx_ptr, int color)
                        
                                La fonction renvoit un unsigned int qui contient les 8/16/32 (tout dépend du 
                                nombre de bits/pixel) bits contenus dans la mémoire vidéo pour coder la couleur 
                                voulue. On mettra ces mêmes bits dans les octets  (de l'image temporaire) 
                                correspondants au pixel voulu. 

Remplissage de l'image : 
                        char *data;
                        int bpp;
                        int line_size:
                        int endian;
                        [...]
                        data = mlx_get_data_addr(img_ptr, &bpp, &line_size, &endian);

Pour un pixel (x, y) dont on veut changer la couleur, le(s) octet(s) du pixel sont à l'adresse :
                        offset = data + (x * (bpp / 8)) + (y * line_size); 
                            (bpp / 8) permet de calculer sur combien d'octets est codé chaque pixel
                        Il ne reste qu'à le(s) garnir avec le(s) octet(s) obtenu(s) par 
                        mlx_get_color_value()

*/


// int mlx_pixel_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color );
// int mlx_string_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string );

int	close2(void *mlx_ptr)
{
	if (!mlx_loop_end(mlx_ptr))
    {
        write(2, "Error when closing window\n", 26);
        return (0);
    }
    return (1);
}

int main()
{
    t_data img;
    void *mlx_ptr;
    void *win_ptr;
    int x;
    int y;
    unsigned int color;
    
    x = 200;
    y = 500;
    color = 0xffffff;
    
    mlx_ptr = mlx_init(); // mlx_ptr : connection identifier
    win_ptr = mlx_new_window(mlx_ptr, 800, 800, "Bonjour\n");
    img.img = mlx_new_image(mlx_ptr, 800, 800);
    img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
   
    // modifier la couleur du pixel (150, 270) :

    t_point u;
    t_point v;
    u.x = 50;
    u.y = 50;
    v.x = 200;
    v.y = 300;
    
    draw_line(&img, u, v, color); // tvb
    
    
    
    
    mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 100, 100);
    
    
    mlx_hook(win_ptr, 33, 1L<<17, close2, mlx_ptr);
    mlx_loop(mlx_ptr);
    
    
    mlx_destroy_image(mlx_ptr, img.img);
    mlx_destroy_window(mlx_ptr, win_ptr); // free(win_ptr)
    free(mlx_ptr);
    
}
