/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cteixido <cteixido@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:10:59 by cteixido          #+#    #+#             */
/*   Updated: 2022/01/28 11:47:26 by cteixido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char		*d;
	const char	*s;

	if ((dst == src) || n == 0)
		return (dst);
	d = (char *)dst;
	s = (char const *)src;
	while (n--)
		d[n] = (const char)s[n];
	return (dst);
}
