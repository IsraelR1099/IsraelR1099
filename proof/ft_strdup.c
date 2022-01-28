/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fscorcel <fscorcel@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:16:23 by fscorcel          #+#    #+#             */
/*   Updated: 2022/01/19 13:05:50 by fscorcel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strdup(const char *s1)
{
	size_t	marker;
	char	*s2;

	marker = 0;
	s2 = malloc (ft_strlen(s1) + 1);
	if (!s2)
		return (0);
	while (marker < (ft_strlen(s1) + 1))
	{
		((unsigned char *)s2)[marker] = ((unsigned char *)s1)[marker];
		marker++;
	}
	return (s2);
}
