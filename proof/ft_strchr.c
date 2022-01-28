/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fscorcel <fscorcel@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:55:56 by fscorcel          #+#    #+#             */
/*   Updated: 2022/01/25 17:31:36 by fscorcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	i = c;

	while (*s)
	{
		if (*s == i)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == i)
	{
		return ((char *)s);
	}
	return (NULL);
}
