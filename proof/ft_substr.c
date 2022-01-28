/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fscorcel <fscorcel@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:49:21 by fscorcel          #+#    #+#             */
/*   Updated: 2022/01/19 16:19:40 by fscorcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)

{
	size_t	marker;
	char	*s2;

	marker = 0;
	s2 = malloc (len + 1);
	if (!s2 || !s)
		return (0);
	while ((start < (ft_strlen(s) + 1)) && marker < len)
	{
		((unsigned char *)s2)[marker] = ((unsigned char *)s)[start + marker];
		marker++;
	}
	s2[marker] = '\0';
	return (s2);
}
