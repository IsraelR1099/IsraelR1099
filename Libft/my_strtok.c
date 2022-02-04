/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:42:51 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/04 14:10:32 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strtok(char *s, char c)
{
	static char	*buffer = NULL;
	char	*token;
	char	*ptr;

	if (!buffer)
		buffer = s;
	token = buffer;
	if (!*buffer)
		return (0);
	while (*buffer  && *buffer != c)
		buffer += 1;
	if (*buffer)
	{
		*buffer = 0;
		buffer += 1;
	}
	return (token);
}

int	main(void)
{
	char	str[] = "hola como estas";
	char	delim = ' ';
	char	*token;

	token = ft_strtok(str, delim);
	while (token)
	{
		printf("%s\n", token);
		token = ft_strtok(NULL, delim);
	}
	return (0);
}

