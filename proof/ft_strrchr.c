/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fscorcel <fscorcel@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:33:36 by fscorcel          #+#    #+#             */
/*   Updated: 2022/01/28 14:55:32 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	i = c;
	size_t		marker;

	marker = ft_strlen(s) + 1;
	while (marker > 0)
	{
		marker --;
		if (s[marker] == i)
		{
			return ((char *)(s + marker));
		}
	}
	return (NULL);
}
