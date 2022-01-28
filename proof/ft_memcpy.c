/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fscorcel <fscorcel@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:11:51 by fscorcel          #+#    #+#             */
/*   Updated: 2022/01/14 19:58:34 by fscorcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	marker;

	if (dst == NULL && src == NULL)
		return (NULL);
	marker = 0;
	while (marker < n)
	{
		((unsigned char *)dst)[marker] = ((unsigned char *)src)[marker];
		marker ++;
	}
	return (dst);
}
