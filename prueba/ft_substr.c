/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:45:37 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/31 20:52:33 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	index;
	size_t	counter;

	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (!ptr || !s)
		return (0);
	index = 0;
	counter = 0;
	while (s[index])
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
