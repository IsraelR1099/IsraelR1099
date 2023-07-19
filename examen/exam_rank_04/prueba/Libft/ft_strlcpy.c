/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:43:10 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/28 14:17:07 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	position;
	int				len_src;

	len_src = ft_strlen(src);
	position = 0;
	if (size != 0)
	{
		while (src[position] != '\0' && position < (size - 1))
		{
			dest[position] = src[position];
			position++;
		}
		dest[position] = '\0';
	}
	return (len_src);
}
