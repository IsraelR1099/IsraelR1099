/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:43:45 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/28 11:31:19 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	position;
	unsigned int	len_dest;
	unsigned int	len_src;
	unsigned int	st_size_dest;

	st_size_dest = ft_strlen(dest);
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	position = 0;
	if (size < 1)
		return (size + len_src);
	while (src[position] != '\0' && len_dest < (size - 1))
	{
		dest[len_dest] = src[position];
		len_dest++;
		position++;
	}
	dest[len_dest] = '\0';
	if (size < st_size_dest)
		return (len_src + size);
	else
		return (st_size_dest + len_src);
}
