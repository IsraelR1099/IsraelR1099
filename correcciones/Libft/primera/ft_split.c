/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cteixido <cteixido@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:15:11 by cteixido          #+#    #+#             */
/*   Updated: 2022/02/09 11:24:20 by cteixido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnumber(const char *s, char c)
{
	size_t	length;
	size_t	number;

		length = 0;
	number = 0;
	while (s[length])
	{
		while (s[length] == c)
			length++;
		if (s[length] && s[length] != c)
			number++;
		while (s[length] != 0 && (s[length] != c))
			length++;
	}
	return (number);
}

static char	*ft_strset(const char *s, char c)
{
	char	*string;
	size_t	length;

	length = 0;
	while (s[length] && s[length] != c)
		length++;
	string = ft_calloc(sizeof(char), length + 1);
	if (!string)
		return (0);
	length = 0;
	while (s[length] && s[length] != c)
	{
		string[length] = s[length];
		length++;
	}
	string[length] = '\0';
	return (string);
}

char	**ft_split(char const *s, char c)
{
	size_t	n;
	size_t	strn;
	char	**strings;

	n = 0;
	strn = ft_strnumber(s, c);
	strings = ft_calloc(sizeof(char **), strn + 1);
	if (!strings)
		return (0);
	while (n < strn)
	{
		while (*s == c)
			s++;
		strings[n] = ft_strset(s, c);
		if (!strings[n])
		{
			while (n > 0)
				free(strings[n--]);
			free(strings);
			return (0);
		}
		s += ft_strlen(strings[n++]);
	}
	strings[n] = 0;
	return (strings);
}
