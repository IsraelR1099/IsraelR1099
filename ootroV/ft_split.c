/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaguilar <vaguilar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 14:18:15 by vaguilar          #+#    #+#             */
/*   Updated: 2022/02/05 08:10:24 by vaguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(const char *s, char c)
{
	int	i;
	int	temp;

	i = 0;
	temp = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
		{
			i++;
		}
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			temp++;
			i++;
		}
	}
	return (temp);
}

static int	ft_lenword(const char *s, char c)
{
	int	x;

	x = 0;
	while (s[x] != '\0' && s[x] != c)
		x++;
	return (x);
}

static char	*ft_getvalue(const char *s, char c)
{
	char	*word;
	int		x;

	x = 0;
	word = (char *)malloc((ft_lenword(s, c) + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (s[x] && s[x] != c)
	{
		word[x] = s[x];
		x++;
	}
	word[x] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		words;
	int		count;

	if (!s)
		return (NULL);
	count = 0;
	words = ft_countwords(s, c);
	array = (char **)malloc ((words + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (*s && count < words)
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
		{
			array[count] = ft_getvalue(s, c);
			while (*s != c && *s != '\0')
				s++;
		}
		count++;
	}
	array[count] = 0;
	return (array);
}
