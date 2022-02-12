/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:43:11 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/12 14:01:49 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buffer;
	int		file;

	buffer = malloc(20 + 1);
	while ((file = read(fd, buffer, 20)))
	{
		buffer[file] = '\0';
		ft_putstr(buffer);
	}
	return (buffer);
}

