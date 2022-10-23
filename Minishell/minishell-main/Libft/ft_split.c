/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:24:32 by irifarac          #+#    #+#             */
/*   Updated: 2022/10/21 11:45:42 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_counter(char const *s, char c)
{
	unsigned int	counter;
	char			*buffer;

	counter = 0;
	buffer = (char *)s;
	while (*buffer)
	{
		while (*buffer == c)
			buffer += 1;
		if (*buffer)
			counter++;
		while (*buffer && !(*buffer == c))
				buffer += 1;
	}
	return (counter);
}

char	**ft_split(const char *s, char c)
{
	char	**ptr;
	size_t	position;
	size_t	len;

	position = 0;
	ptr = malloc(sizeof(char *) * (ft_counter(s, c) + 1));
	if (!s || !ptr)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			ptr[position++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	ptr[position] = NULL;
	return (ptr);
}
