/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fscorcel <fscorcel@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:37:25 by fscorcel          #+#    #+#             */
/*   Updated: 2022/01/28 13:34:09 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{	
	size_t	x;
	size_t	y;
	size_t	size_dst;
	size_t	size_src;

	x = ft_strlen(dst);
	y = 0;
	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	if (dstsize < 1)
		return (size_src + dstsize);
	while (src[y] && x < dstsize - 1)
	{
		dst[x] = src[y];
		x++;
		y++;
	}
	dst[x] = '\0';
	if (dstsize < size_dst)
		return (size_src + dstsize);
	else
		return (size_dst + size_src);
}
