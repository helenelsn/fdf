/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Helene <Helene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 23:35:36 by Helene            #+#    #+#             */
/*   Updated: 2023/01/22 23:44:16 by Helene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLING_H
# define FILLING_H

/*
Pour une forme CONTINUE A à remplir de la même couleur qu'une forme B, la fonction de
remplissage se rappelle elle-même 4 fois avec les coordonnées de ses voisins,
sauf si un voisin est en dehors de A ou n'est plus dans l'image
    -> il faut ainsi pouvoir connaître la couleur d'un pixel :
*/

unsigned int    get_pixelcolor_from_image(t_data *img, int x, int y); // avec (x, y) les coordonnées du pixel

#endif