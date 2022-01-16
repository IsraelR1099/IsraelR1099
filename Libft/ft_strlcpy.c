/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 10:29:09 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/14 12:55:07 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	position;
	int	len_src;

	len_src = 0;
	while (src[len_src] != '\0')
	{
		len_src++;
	}
	
	position = 0;
	while (src[position] != '\0' && position < (size - 1))
	{
		dest[position] = src[position];
		position++;
	}
	dest[position] = '\0';

	return (len_src);
}
