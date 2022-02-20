/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:43:11 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/20 21:10:58 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char const *s, char c)
{
	static char	*buffer = NULL;
	char		*token;
	char		*dup_token;

	
	if (!buffer)
		buffer = (char *)s;
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

char	*ft_read_file(int fd)
{
	static char	*whole_str = NULL;
	char		*token;
	
	if (!whole_str)
	{
		whole_str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		whole_str = temp_str;
		if (!whole_str)
			return (0);
	}
	if (calls_function() > 1)
	{
		whole_str = ft_strjoin(whole_str, temp_str);
	}
	token = ft_line(whole_str, '\n');
	free (temp_str);
	return (token);
}

char	*get_next_line(int fd)
{
	char	*temp_str;
	char	*line;
	int	nbr_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp_str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_str)
	{
		free (temp_str);
		return (0);
	}
	nbr_bytes = 1;
	while (!(ft_strchr(temp_str, '\n')) && nbr_bytes != 0)
	{
		nbr_bytes = read(fd, temp_str, BUFFER_SIZE);
		temp_str[nbr_bytes] = '\0';
	}
	line = ft_read_file(temp_str);
	return (line);
}
