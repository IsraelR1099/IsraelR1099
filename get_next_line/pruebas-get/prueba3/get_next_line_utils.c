/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:02:20 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/27 20:12:39 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "tc3.h"

size_t	ft_strlen(const char *str)
{
	size_t	position;

	position = 0;
	while (str[position] != '\0')
		position++;
	return (position);
}

void	*ft_memset(void	*dest, int ch, size_t count)
{
	unsigned int	position;
	char			*new_dest;

	new_dest = (char *)dest;
	position = 0;
	while (position < count)
	{
		new_dest[position] = (char)ch;
		position++;
	}
	return (new_dest);
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	ptr = malloc (num * size);
	if (ptr == NULL)
	{
		return (0);
	}
	ft_memset(ptr, 0, num * size);
	return (ptr);
}

/*char	*ft_substr(char const *s, unsigned int start, size_t len)
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
}*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return ((char *) ft_calloc(1, sizeof(char)));
	if (ft_strlen(s) <= start + len)
		substr = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (s[start] && i < len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
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
	char			*ptr;

	if (!s1 || !s2)
		return (0);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (ptr == NULL)
		return (0);
	if (ptr)
	{
		ft_memcpy(ptr, s1, lens1);
		ft_memcpy(ptr + lens1, s2, lens2 + 1);
	}
	ptr[lens1 + lens2] = '\0';
	free((void *)s1);
	s1 = NULL;
	return (ptr);
}
