/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:43:11 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/15 14:22:57 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*str;
	int			file;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);

	line = ft_line(fd, str);

	//Loop para leer hasta que read sea 0 es decir llega al final del archivo
/*	while ((file = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[file] = '\0';
		ft_putstr(buffer);
	}
	file = read(fd, buffer, BUFFER_SIZE);
	buffer[file] ='\0';
	ft_putstr(buffer);*/

	


	printf("Numero de bytes leidos: %d\n", file);
	return (buffer);
}

