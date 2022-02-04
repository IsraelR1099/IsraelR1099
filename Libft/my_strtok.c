/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:42:51 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/04 21:10:01 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strtok(char *s, char c)
{
	static char	*buffer = NULL;
	char	*token;

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
	char	*token[3];
	char	**ptr[3];
//	int	position;

//	position = 0;
	token[0] = ft_strtok(str, delim);
	ptr[0] = token[0];
	printf("token es %s\n", (char *)token[0]);
	printf("ptr 0 es %s\n", (char *)ptr[0]);
	token[1] = ft_strtok(str, delim);
//	ptr[1] = &token;
	printf("token es %s\n", (char *)token[1]);
//	printf("ptr 1 es %s\n", (char *)ptr);
	token[2] = ft_strtok(str, delim);
	printf("token es %s\n", (char *)token[2]);
/*	while (token)
	{
		ptr[position] = ft_strtok(NULL, delim);
		position++;
		printf("ptr es %s\n", ptr);
		printf("%s\n", token);
		token = ft_strtok(NULL, delim);
	}
		printf("ptr es %s\n", ptr);*/
	return (0);
}

