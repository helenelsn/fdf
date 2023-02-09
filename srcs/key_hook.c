/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:35:08 by hlesny            #+#    #+#             */
/*   Updated: 2023/02/09 18:29:33 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press(int keycode, void *mlx_ptr)
{
    if (keycode == KEY_ESC)
    {
        if (!mlx_loop_end(mlx_ptr))
        {
            write(2, "Error when closing window\n", 26);
            return (0);
        }
    }
    return (1);
}