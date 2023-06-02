/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:02:54 by irifarac          #+#    #+#             */
/*   Updated: 2023/01/27 20:38:29 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*ft_read_file(char *whole_str, char temp_str[], int fd)
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

static char	*ft_line(char *whole_str)
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

static char	*ft_update_str(char *whole_str)
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

char	*ft_get_next_line(int fd)
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
