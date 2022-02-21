/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:56:53 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/21 23:06:50 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_line(char const *s, char c)
{
	//static char	*buffer = NULL;
	char		*token;

	//buffer = (char *)s;
	token = ft_read_file;
	if (!*buffer)
	{
		buffer = 0;
		return (0);
	}
	while (*buffer && *buffer != c)
		buffer += 1;
	if (*buffer)
	{
		*buffer = 0;
		buffer += 1;
	}
	return (token);
}

static char	*ft_read_file(char *str, int fd)
{
	static char	*whole_str = NULL;
	int		nbr_bytes;

	if (!whole_str)
	{
		whole_str = (char *)malloc(sizeof(*whole_str) * (BUFFER_SIZE + 1));
		if (!whole_str)
			return (0);
	}
	while (!ft_strchr(temp_str, '\n'))
	{
		whole_str = ft_strjoin(whole_str, temp_str);
	}
	return (whole_str);
}

char	*get_next_line(int fd)
{
	char		*temp_str;
	int		nbr_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	temp_str = (char *)malloc(sizeof(*temp_str) * (BUFFER_SIZE + 1));
	if (!temp_str)
	{
		free(temp_str);
		return (0);
	}
	nbr_bytes = 1;
	nbr_bytes = read(fd, temp_str, BUFFER_SIZE);
	if (nbr_bytes == -1)
	{
		free(temp_str);
		return (0);
	}
	if (nbr_bytes > 0)
	{
		temp_str[nbr_bytes] = '\0';
		ft_read_file(temp_str, fd);

