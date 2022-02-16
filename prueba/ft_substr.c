/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:45:37 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/16 10:32:09 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	index;
	size_t	counter;

	if (len > ft_strlen(s))
		ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	else
		ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (0);
	index = 0;
	counter = 0;
	while (s[index] != '\0')
	{
		if (index >= start && counter < len)
		{
			ptr[counter] = s[index];
			counter++;
		}
		index++;
	}
	ptr[counter] = '\0';
	return (ptr);
}
