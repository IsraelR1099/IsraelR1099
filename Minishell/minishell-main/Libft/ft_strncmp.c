/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:10:01 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/10 18:10:42 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t number)
{
	size_t	position;

	if (!str1 || !str2 || !ft_strlen(str2))
		return (1);
	position = 0;
	if (!number)
		return (0);
	while (str1[position] && (str1[position] == str2[position])
		&& position < (number - 1))
	{
		position++;
	}
	return ((unsigned char)str1[position] - (unsigned char)str2[position]);
}
