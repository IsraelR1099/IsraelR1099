/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:40:02 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/01 13:54:52 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	ft_len(int fd)
{
	char	tmp[BUFFER_SIZE + 1];
	int		len;
	int		nbr_bytes;

	len = 0;
	nbr_bytes = read(fd, tmp, BUFFER_SIZE);
	while (nbr_bytes > 0)
	{
		tmp[nbr_bytes] = '\0';
		if (ft_strchr(tmp, '\n'))
			len++;
		nbr_bytes = read(fd, tmp, BUFFER_SIZE);
	}
	close(fd);
	return (len);
}

int	ft_check_id(int fd)
{
	char	**lines;
	int		i;
	int		len;

	len = ft_len(fd);
	i = 0;
	lines = malloc(sizeof(char *) * (len + 1));
	if (!lines)
		return (-1);
	while (len--)
	{
		lines[i] = ft_get_next_line(fd);
		i++;
	}
	lines[i] = NULL;
	return (0);
}

