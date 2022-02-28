/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalmela- <aalmela-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:19:39 by aalmela-          #+#    #+#             */
/*   Updated: 2022/02/15 12:26:14 by aalmela-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	int		size1;
	int		size2;
	int		i;
	int		j;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	r = (char *)malloc(size1 + size2 +1);
	if (r == NULL)
		return (NULL);
	i = 0;
	while (i < size1)
	{
		r[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < size2)
	{
		r[i + j] = s2[j];
		j ++;
	}
	r[i + j] = '\0';
	return (r);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned long	i;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		i = 0;
	else if (ft_strlen(s + start) <= len)
		i = ft_strlen(s + start);
	else
		i = len;
	ret = (char *)malloc(i + 1);
	if (ret == NULL)
		return (NULL);
	ret[i] = 0;
	if (i > 0)
		ft_strlcpy(ret, &s[start], i + 1);
	return (ret);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size -1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
