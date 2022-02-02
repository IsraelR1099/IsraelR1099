/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilascu <ilascu@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:56:19 by ilascu            #+#    #+#             */
/*   Updated: 2022/01/21 13:47:11 by ilascu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	char	*c;
	char	*i;

	c = (char *)dest;
	i = (char *)src;
	while (dest == src || !n)
		return (dest);
	if (i < c)
	{
		while (n > 0)
		{
			c[n - 1] = i[n -1];
			n--;
		}
	}
	else
		ft_memcpy(c, i, n);
	return (c);
}
