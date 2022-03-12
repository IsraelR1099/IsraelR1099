/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:31:43 by irifarac          #+#    #+#             */
/*   Updated: 2022/03/02 10:12:28 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*whole_str;
	char		temp_str[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!whole_str)
	{
		whole_str = ft_strdup("");
		if (!whole_str)
			return (NULL);
	}
	whole_str = ft_read_file(whole_str, temp_str, fd);
	if (!whole_str)
		return (NULL);
	line = ft_line(whole_str);
	whole_str = ft_update_str(whole_str);
	return (line);
}

char	*ft_read_file(char *whole_str, char temp_str[], int fd)
{
	int	nbr_bytes;

	nbr_bytes = read(fd, temp_str, BUFFER_SIZE);
	while (nbr_bytes >= 0)
	{
		temp_str[nbr_bytes] = '\0';
		if (nbr_bytes == 0)
			return (whole_str);
		whole_str = ft_strjoin(whole_str, temp_str);
		if (ft_strchr(whole_str, '\n'))
			return (whole_str);
		nbr_bytes = read(fd, temp_str, BUFFER_SIZE);
	}
	free(whole_str);
	whole_str = NULL;
	return (0);
}

char	*ft_line(char *whole_str)
{
	char	*line;
	int		position;

	position = 0;
	if (!whole_str[position])
		return (0);
	while (whole_str[position] && whole_str[position] != '\n')
		position++;
	line = ft_substr(whole_str, 0, position + 1);
	return (line);
}

char	*ft_update_str(char *whole_str)
{
	char	*new_whole_str;
	int		position;
	int		position_new;
	int		len_str;

	position = 0;
	len_str = ft_strlen(whole_str);
	while (whole_str[position] && whole_str[position] != '\n')
		position++;
	if (!whole_str[position])
	{
		free(whole_str);
		return (0);
	}
	new_whole_str = (char *)malloc(sizeof(char) * (len_str - position + 1));
	if (!new_whole_str)
		return (0);
	position++;
	position_new = 0;
	while (whole_str[position])
		new_whole_str[position_new++] = whole_str[position++];
	new_whole_str[position_new] = '\0';
	free(whole_str);
	whole_str = NULL;
	return (new_whole_str);
}

size_t	ft_strlen(const char *str)
{
	size_t	position;

	position = 0;
	while (str[position] != '\0')
		position++;
	return (position);
}
