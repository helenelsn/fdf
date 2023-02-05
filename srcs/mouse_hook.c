/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:34:49 by hlesny            #+#    #+#             */
/*   Updated: 2023/02/05 18:34:59 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close2(void *mlx_ptr)
{
	if (!mlx_loop_end(mlx_ptr))
    {
        write(2, "Error when closing window\n", 26);
        return (0);
    }
    return (1);
}