/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:43:45 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/17 12:34:46 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char			*new_src;
	unsigned int	position;
	unsigned int	len_dest;
	int				len_src;

	new_src = (char *)src;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(new_src);
	position = 0;
	while (new_src[position] != '\0' && len_dest < (size - 1))
	{
		dest[len_dest] = new_src[position];
		len_dest++;
		position++;
	}
	dest[len_dest] = '\0';
	return (len_dest + len_src - position);
}
