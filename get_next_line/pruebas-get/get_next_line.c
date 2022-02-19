/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:43:11 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/19 12:26:23 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*str;
	int		result;

	result = calls_function();
	printf("calls function is %d\n", result);

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read_file(fd);
	//printf("line en get next line es '%s'\n", line);
	printf("el buffer size es %d\n", BUFFER_SIZE);

	//Loop para leer hasta que read sea 0 es decir llega al final del archivo
/*	while ((file = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[file] = '\0';
		ft_putstr(buffer);
	}
	file = read(fd, buffer, BUFFER_SIZE);
	buffer[file] ='\0';
	ft_putstr(buffer);*/
	return (str);
}

