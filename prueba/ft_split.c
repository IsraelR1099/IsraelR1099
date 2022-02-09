/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:44:28 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/09 20:43:54 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtok(char *s, char c)
{
	static char	*buffer = NULL;
	char		*token;
	char		*dup_token;
	int	i;

	i = 0;
	i = i + 1;
	if (!buffer)
		buffer = s;
	token = buffer;
	if (!*buffer)
	{
		buffer = 0;
		return (0);
	}
	while (*buffer == c)
		buffer += 1;
	while (*buffer && *buffer != c)
		buffer += 1;
	if (*buffer)
	{
			*buffer = 0;
			buffer += 1;
	}
	while (*token == c)
		token += 1;
	dup_token = ft_strdup(token);
	return (dup_token);
}

int	ft_counter(char const *s, char c)
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

char	**ft_split(char const *s, char c)
{
	int		position;
	char	**ptr;
	char	*token;
	char	*new_s;
	char	*delim;

	delim = &c;
	new_s = ft_strtrim(s, delim);
	ptr = (char **)malloc(sizeof(char *) * (ft_counter(s, c) + 1));
	if (!ptr)
		return (0);
	token = ft_strtok(new_s, c);
	position = 0;
	while (position < ft_counter(s, c))
	{
		ptr[position] = token;
		token = ft_strtok(NULL, c);
		position++;
	}
	ptr[position] = NULL;
	return (ptr);
}
