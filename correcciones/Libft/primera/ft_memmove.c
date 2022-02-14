/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cteixido <cteixido@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:35:43 by cteixido          #+#    #+#             */
/*   Updated: 2022/02/04 12:48:10 by cteixido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	if (!dst && !src)
		return (0);
	d = (char *)dst;
	s = (char *)src;
	if (d > s)
	{
		while (len--)
		{
			*(d + len) = *(s + len);
		}
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}
