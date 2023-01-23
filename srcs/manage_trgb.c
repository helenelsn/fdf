/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_trgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 01:38:20 by hlesny            #+#    #+#             */
/*   Updated: 2023/01/19 01:38:40 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// color integer : TRGB (Transparency, Red, Green, Blue)
int create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
    return (t << 24 | r << 16 | g << 8 |b); // retourne un int ??
}

unsigned char get_t(int trgb)
{
    return (trgb >> 24); // 0xFF tient sur un octet, avec chaque bit set a 1
}

unsigned char get_r(int trgb)
{
    return ((trgb >> 16) & 0xFF);
}

unsigned char get_g(int trgb)
{
    return ((trgb >> 8) & 0xFF);
}

unsigned char get_b(int trgb)
{
    return (trgb & 0xFF);
}