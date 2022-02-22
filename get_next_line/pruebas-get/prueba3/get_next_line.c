/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:56:53 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/22 14:17:29 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_line(char *str, char c)
{
	static char	*buffer = NULL;
	char		*token;

	buffer = str;
	token = buffer;
	if (!*buffer)
	{
		buffer = 0;
		return (0);
	}
	while (*buffer && *buffer != c)
		buffer += 1;
	if (*buffer)
	{
		buffer += 1;
		*buffer = 0;
	}
	return (token);
}

static void	*ft_iter(char *str)
{
	while (*str != '\n')
		str += 1;
	if (*str)
		str += 1;
}

static char	*ft_read_file(char *temp_str, int fd)
{
	static char	*whole_str = NULL;
	char		*token2;
	int			nbr_bytes;

	if (!whole_str)
	{
		whole_str = (char *)malloc(sizeof(*whole_str) * (BUFFER_SIZE + 1));
		if (!whole_str)
			return (0);
	}
	nbr_bytes = 1;
	while (!ft_strchr(temp_str, '\n') && nbr_bytes > 0)
	{
		nbr_bytes = read(fd, temp_str, BUFFER_SIZE);
		if (nbr_bytes == -1)
		{
			free(temp_str);
			free(whole_str);
			return (0);
		}
		temp_str[nbr_bytes] = '\0';
		whole_str = ft_strjoin(whole_str, temp_str);
	}
	token2 = ft_strdup(whole_str);
/*	while (*whole_str != '\n')
		whole_str += 1;
	if (*whole_str)
		whole_str += 1;*/
	ft_iter(whole_str);
	free(temp_str);
	return (token2);
}

char	*get_next_line(int fd)
{
	char		*temp_str;
	char		*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp_str = (char *)malloc(sizeof(*temp_str) * (BUFFER_SIZE + 1));
	if (!temp_str)
	{
		free(temp_str);
		return (0);
	}
	str = ft_read_file(temp_str, fd);
	line = ft_line(str, '\n');
	return (line);
}
