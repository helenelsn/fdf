/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:35:08 by hlesny            #+#    #+#             */
/*   Updated: 2023/02/12 16:55:15 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     go_rotate(int keycode)
{
    return (keycode == KEY_LEFT || keycode == KEY_RIGHT
        || keycode == KEY_UP || keycode == KEY_DOWN);
}

int	key_press(int keycode, void *mlx_ptr)
{
    //printf("%i\n", keycode);
//     printf("Cristina la plus belle d monde\n");
//     if (keycode == 100)
//         printf("droite bg\n")

    if (keycode == KEY_ESC)
    {
        if (!mlx_loop_end(mlx_ptr))
        {
            write(2, "Error when closing window\n", 26);
            return (0);
        }
    }
    // if (go_rotate(keycode))
    //     rotate()

    return (1);
}