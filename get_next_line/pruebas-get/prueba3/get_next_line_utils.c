/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:02:20 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/22 20:42:16 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	position;

	position = 0;
	while (str[position] != '\0')
		position++;
	return (position);
}

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	const char	*new_src;
	char		*new_dest;

	new_src = (char *)src;
	new_dest = (char *)dest;
	if (dest == NULL || src == NULL)
		return (NULL);
	while (count--)
	{
		*new_dest++ = *new_src++;
	}
	return (dest);
}

char	*ft_strchr(const char *str, int ch)
{
	int	position;

	position = 0;
	while (str[position] != '\0')
	{
		if (str[position] == (char)ch)
			return ((char *)str + position);
		position++;
	}
	if (str[position] == (char)ch)
		return ((char *)str + position);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;

	dest = malloc (ft_strlen((char *)s1) + 1);
	if (dest == NULL)
		return (0);
	ft_memcpy(dest, s1, ft_strlen((char *)s1) + 1);
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	lens1;
	unsigned int	lens2;
	char			*ptr1;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	ptr1 = (char *)malloc(sizeof(char) * (lens1 + lens2 +1));
	if (ptr1 == NULL)
		return (0);
	if (ptr1)
	{
		ft_memcpy(ptr1, s1, lens1);
		ft_memcpy(ptr1 + lens1, s2, lens2 + 1);
	}
	ptr1[lens1 + lens2] = '\0';
	return (ptr1);
}
