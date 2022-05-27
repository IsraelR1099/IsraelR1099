/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mporras- <manon42bcn@yahoo.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 23:51:31 by mporras-          #+#    #+#             */
/*   Updated: 2022/01/29 23:51:35 by mporras-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

static int	ft_get_endline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

static char	*ft_delete_line_from_buffer(char **buffer, int *nl_len)
{
	char	*rst;

	if (nl_len[0] == nl_len[1] || (nl_len[0] == 0 && nl_len[1] > 0))
	{
		free(*buffer);
		return (NULL);
	}
	rst = ft_substr_gnl(*buffer, nl_len[0], nl_len[1] - nl_len[0], &nl_len[0]);
	free(*buffer);
	return (rst);
}

static char	*ft_line_proccess(char **buffer, int bytes, int *nl_len)
{
	char	*rst;

	if (!*buffer)
		return (NULL);
	if (nl_len[0] == 0 && bytes == 0)
	{
		rst = ft_strdup(*buffer);
		*buffer = ft_delete_line_from_buffer(buffer, &nl_len[0]);
	}
	else
	{
		rst = ft_substr_gnl(*buffer, 0, nl_len[0], &nl_len[0]);
		*buffer = ft_delete_line_from_buffer(buffer, &nl_len[0]);
	}
	return (rst);
}

static char	*ft_buffer_reader(int fd, char **buffer, char *reader, int *nl_len)
{
	int	bytes;
	int	nl_reader;

	bytes = 0;
	while (nl_len[0] == 0)
	{
		bytes = read(fd, reader, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		reader[bytes] = '\0';
		nl_len[1] += bytes;
		nl_reader = ft_get_endline(reader);
		if (!*buffer)
			*buffer = ft_strdup(reader);
		else
			*buffer = ft_strjoin_gnl(*buffer, reader, bytes, &nl_len[0]);
		if (*buffer == NULL)
			break ;
		if (nl_reader > 0)
			nl_len[0] = (nl_len[1] - bytes) + nl_reader;
	}
	if (bytes < 0 || !*buffer)
		return (NULL);
	return (ft_line_proccess(buffer, bytes, &nl_len[0]));
}

char	*get_next_line(int fd)
{	
	static char	*buffer = NULL;
	char		*rst;
	char		*reader;
	int			nl_len[2];

	if (fd < 0 || fd > 257 || BUFFER_SIZE < 1)
		return (NULL);
	nl_len[0] = ft_get_endline(buffer);
	nl_len[1] = ft_strlen(buffer);
	if (nl_len[0] == 0)
	{
		reader = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (reader == NULL)
			return (NULL);
		rst = ft_buffer_reader(fd, &buffer, reader, &nl_len[0]);
		free (reader);
	}
	else
		rst = ft_line_proccess(&buffer, 0, &nl_len[0]);
	return (rst);
}
