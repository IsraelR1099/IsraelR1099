/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fscorcel <fscorcel@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:11:51 by fscorcel          #+#    #+#             */
/*   Updated: 2022/01/15 12:40:01 by fscorcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	marker;

	marker = 0;
	while (marker < n)
	{
		if (((unsigned char *)s)[marker] == ((unsigned char)c))
			return (((unsigned char *)s) + marker);
		marker ++;
	}
	return (NULL);
}
