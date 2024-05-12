/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 17:45:37 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/23 13:26:54 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	lenstr;
	size_t	counter;

	if (!s)
		return (NULL);
	lenstr = ft_strlen(s);
	if (len >= (lenstr - start))
		len = lenstr - start;
	if (start > lenstr)
		len = 0;
	ptr = (char *)malloc(sizeof(*ptr) * (len + 1));
	if (!ptr)
		return (0);
	counter = 0;
	while (counter < len && start < ft_strlen(s))
	{
			ptr[counter++] = s[start++];
	}
	ptr[counter] = '\0';
	return (ptr);
}
