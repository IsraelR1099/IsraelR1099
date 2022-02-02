/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilascu <ilascu@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:45:49 by ilascu            #+#    #+#             */
/*   Updated: 2022/01/21 17:10:20 by ilascu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	c;
	size_t	i;

	c = ft_strlen(src);
	i = 0;
	dest = (char *)malloc(sizeof(char) * (c + 1));
	if (dest == 0)
		return (0);
	while (i < c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
