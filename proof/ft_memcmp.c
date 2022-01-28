/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fscorcel <fscorcel@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:23:45 by fscorcel          #+#    #+#             */
/*   Updated: 2022/01/18 16:32:25 by fscorcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	m;

	m = 0;
	while (m < n)
	{
		if (((unsigned char *)s1)[m] != ((unsigned char *)s2)[m])
			return (((unsigned char *)s1)[m] - ((unsigned char *)s2)[m]);
		m++;
	}
	return (0);
}
