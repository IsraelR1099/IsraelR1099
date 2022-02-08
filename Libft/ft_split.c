/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:44:28 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/08 09:44:12 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtok(char *s, char c)
{
	static char	*buffer = NULL;
	char		*token;
	char		*dup_token;

	if (!buffer)
		buffer = s;
	token = buffer;
	if (!*buffer)
		return (0);
	while (*buffer && *buffer != c)
		buffer += 1;
	if (*buffer)
	{
			*buffer = 0;
			buffer += 1;
	}
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

void	ft_clean_space(char *s, char c)
{
	int	position;
	int	len;
	int	temp;
	int	position_new;

	len = ft_strlen(s);
	position = 0;
	while (position < len)
	{
		if (s[position] == c && s[position + 1] == c)
		{
			temp = position;
			position_new = position;
			while (position_new < (len - 1))
			{
				s[position_new] = s[position_new + 1];
				position_new++;
			}
			len--;
			s[len] = '\0';
			position = 0;
		}
		position++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		position;
	char	**ptr;
	char	*token;
	char	*delim;
	char	*new_s;

	delim = &c;
	new_s = ft_strtrim(s, delim);
	ft_clean_space(new_s, c);
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
