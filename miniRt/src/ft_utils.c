/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:53:28 by irifarac          #+#    #+#             */
/*   Updated: 2023/01/11 20:58:29 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/miniRT.h"

size_t	ft_strlen(const char *str)
{
	int	position;

	if (!str)
		return (0);
	position = 0;
	while (str[position] != '\0')
		position++;
	return (position);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	position;

	position = 0;
	while (str1[position] && (str1[position] == str2[position]))
		position++;
	return ((unsigned char)str1[position] - (unsigned char)str2[position]);
}
