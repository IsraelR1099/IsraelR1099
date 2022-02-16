/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:43:11 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/16 14:41:41 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	*whole_str;
	int		fd2;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);

	whole_str = (char *)malloc(sizeof(char) * (48 + 1));
	fd2 = read(fd, whole_str, 48);
	if (fd2 == -1)
		return (0);
	line = ft_line(whole_str, '\n');
	//printf("line en get next line es '%s'\n", line);

	//Loop para leer hasta que read sea 0 es decir llega al final del archivo
/*	while ((file = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[file] = '\0';
		ft_putstr(buffer);
	}
	file = read(fd, buffer, BUFFER_SIZE);
	buffer[file] ='\0';
	ft_putstr(buffer);*/
	return (line);
}

