/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:44:28 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/04 14:10:23 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static char	*ft_new_string(char const *s, char (*f)(char *, const char *, size_t), char c)
{
	char	new_str;
	int		position;

	position = 0;
	while (s[position] != '\0')
	{
		if (s + position != c)
		{
			ft_strlcpy(new_str, s + position, );
		}
		position++;
	}
	return
}

static int	ft_len(char const *s, char c)
{
	int i;

	i = 0;
	while (*s != c)
	{
*/
char	*ft_strtok(char *s, char c)
{
	static char	*buffer = NULL;
	char	*token;
	char	*ptr;
	
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
	ptr = malloc(ft_strlen(token) + 1);
	return (token);
}

static int	ft_counter(char const *s, char c)
{
	unsigned int	counter;
	char	*buffer;

	counter = 0;
	buffer = (char *)s;
	while (*buffer)
	{
		while (*buffer == c)
			buffer += 1;
		if (*buffer)
			counter++;
		while (*buffer & !(*buffer == c))
			buffer += 1;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	int	position;
	char	**ptr;
	char	*token;

	ptr = malloc(sizeof(char *) * (ft_counter(s, c) + 1));
	token = ft_strtok((char *)s, c);
	position = 0;
	if (!ptr)
		return (0);
	while (position < ft_counter(s, c))
	{
		ptr[position] = ft_strtok(NULL, c);
		position++;
	}
	return (ptr);
}
