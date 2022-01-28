/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fscorcel <fscorcel@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:14:11 by fscorcel          #+#    #+#             */
/*   Updated: 2022/01/14 19:55:07 by fscorcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	marker;

	if (dst == NULL && src == NULL)
		return (NULL);
	marker = 0;
	if (dst <= src)
	{
		while (marker < len)
		{
			((unsigned char *)dst)[marker] = ((unsigned char *)src)[marker];
			marker ++;
		}
	}
	else
	{
		while (len > 0)
		{
			((unsigned char *)dst)[len - 1] = ((unsigned char *)src)[len - 1];
			len --;
		}
	}
	return (dst);
}
