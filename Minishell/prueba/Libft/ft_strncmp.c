/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:10:01 by irifarac          #+#    #+#             */
/*   Updated: 2022/09/07 11:33:59 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t number)
{
	size_t	position;

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
