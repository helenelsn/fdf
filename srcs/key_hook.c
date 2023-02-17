/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:35:08 by hlesny            #+#    #+#             */
/*   Updated: 2023/02/13 14:34:07 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     go_rotate(int keycode)
{
    return (keycode == KEY_LEFT || keycode == KEY_RIGHT
        || keycode == KEY_UP || keycode == KEY_DOWN);
}

int	key_press(int keycode, t_data *data)
{
    //printf("%i\n", keycode);
//     printf("Cristina la plus belle d monde\n");
//     if (keycode == 100)
//         printf("droite bg\n")

    if (keycode == KEY_ESC)
    {
        if (!mlx_loop_end(data->mlx_ptr))
        {
            write(2, "Error when closing window\n", 26);
            return (0);
        }
    }
    if (keycode == KEY_LEFT || keycode == KEY_RIGHT
        || keycode == KEY_UP || keycode == KEY_DOWN)
        rotate(data, keycode);
    else if (keycode == KEY_I || keycode == KEY_O)
        zoom(data, keycode);
    else if (keycode == KEY_R || keycode == KEY_L 
        || keycode == KEY_U || keycode == KEY_D)
        translate(data, keycode);
    

    return (1);
}