/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:14:33 by hlesny            #+#    #+#             */
/*   Updated: 2023/02/09 18:29:45 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_HOOKS_H
# define KEY_HOOKS_H

# define KEY_ESC    53
//# define KEY_I      34
//# define KEY_O      
//# define KEY_R      
//# define KEY_L
# define KEY_LEFT   123
# define KEY_RIGHT  124
# define KEY_DOWN   125
# define KEY_UP     126

int	key_press(int keycode, void *mlx_ptr);

#endif