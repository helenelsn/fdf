/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlesny <hlesny@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:05:22 by hlesny            #+#    #+#             */
/*   Updated: 2023/02/01 23:18:21 by hlesny           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char *str, int len)
{
	int		i;
	char	*substring;

	i = 0;
	substring = malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	while (i < len && str[i])
	{
		substring[i] = str[i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

char	*ft_strncat(char *line, char *buffer, int len)
{
	int		l_len;
	char	*tmp;
	int		i;

	if (!len)
		len = ft_strlen(buffer); // pour pouvoir l'utiliser dans get_coordinates()
	i = -1;
	l_len = ft_strlen(line);
	tmp = malloc(sizeof(char) * (l_len + len + 1));
	if (!tmp)
		return (NULL);
	while (++i < l_len)
		tmp[i] = line[i];
	i = -1;
	while (++i < len)
		tmp[l_len + i] = buffer[i];
	tmp[l_len + i] = '\0';
	free(line);
	return (tmp);
}
