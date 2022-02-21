/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:56:53 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/21 14:00:20 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_line(char const *s, char c)
{
	static char	*buffer = NULL;
	char		*token;

	buffer = (char *)s;
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
		*buffer = 0;
		buffer += 1;
	}
	return (token);
}

