/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilascu <ilascu@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:12:23 by ilascu            #+#    #+#             */
/*   Updated: 2022/01/25 19:54:20 by ilascu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*dest;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < len)
		dest = (char *)malloc(ft_strlen(s) + 1);
	else if (start > ft_strlen(s))
		dest = (char *)malloc(1);
	else
		dest = (char *)malloc(len + 1);
	if (!dest)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
			dest[j++] = s[i];
		i++;
	}
	dest[j] = '\0';
	return (dest);
}	
