/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:02:20 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/19 21:02:44 by irifarac         ###   ########.fr       */
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

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
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

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	position;
	int				len_src;

	len_src = ft_strlen(src);
	position = 0;
	if (size != 0)
	{
		while (src[position] != '\0' && position < (size - 1))
		{
			dest[position] = src[position];
			position++;
		}
		dest[position] = '\0';
	}
	return (len_src);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;

	dest = malloc (ft_strlen((char *)s1) + 1);
	if (dest == NULL)
		return (0);
	ft_strlcpy(dest, s1, ft_strlen((char *)s1) + 1);
	return (dest);
}

void	*ft_realloc(void *ptr, size_t originalLen, size_t newLen)
{
	void	*new_ptr;

	printf("line en ft realloc es ****%s***\n", (char *)ptr);
	if (!newLen)
	{
		free(ptr);
		return (NULL);
	}
	else if (!ptr)
		return (malloc(newLen));
	else if (newLen <= originalLen)
		return (ptr);
	else
	{
		new_ptr = malloc(sizeof(char) * newLen);
		if (!new_ptr)
			return (0);
		if (new_ptr)
		{
			printf("holaaaaaaaaaaaa reallooooc\n");
			printf("line en ft realloc es ****%s***\n", (char *)ptr);
			ft_memcpy(new_ptr, ptr, originalLen);
			free(ptr);
		}
		return (new_ptr);
	}
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

int	calls_function()
{
	static int	count;

	count ++;
	return (count);
}




