/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 13:42:51 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/06 22:55:10 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strtok(char *s, char c)
{
	static char	*buffer = NULL;
	char	*token;

//	printf("token es igual a '%s'\n", token);
	if (!buffer)
		buffer = s;
	token = buffer;
	if (!*buffer)
		return (0);
	while (*buffer  && *buffer != c)
		buffer += 1;
	if (*buffer && buffer)
	{
		*buffer = 0;
		buffer += 1;
	}
//	printf("token es igual a '%s'\n", token);
	return (token);
}
static int	ft_counter(char const *s, char c)
{
	unsigned int	counter;
	char	*buffer1;

	counter = 0;
	buffer1 = (char *)s;
	while (*buffer1)
	{
		while (*buffer1 == c)
			buffer1 += 1;
		if (*buffer1)
			counter++;
		while (*buffer1 && !(*buffer1 == c))
			buffer1 += 1;
	}
	return (counter);
}

int	main(void)
{
	int	position;
	char	**ptr;
	char	*token;
	int	n_times;
	char	*s = "  hola como estas todo   bien";
	char	c = ' ';
	char	dup[ft_strlen(s) + 1];

	n_times = ft_counter(s, c);
	printf("n times es %d\n", n_times);
	position = 0;
	ft_strlcpy(dup, (char *)s, ft_strlen(s) + 1);
	ptr = (char **)malloc(sizeof(char *) * (n_times + 1));
	if (!ptr)
		return (0);
	token = ft_strtok(dup, c);
	printf("el resultado de token es %s\n", token);
	while (position < n_times)
	{
		ptr[position] = token; 
		token = ft_strtok("a", c);
		position++;
	}
	printf("el resultado es %s\n", ptr[0]);
	printf("el resultado es %s\n", ptr[1]);
	printf("el resultado es %s\n", ptr[2]);
	printf("el resultado es %s\n", ptr[3]);
	printf("el resultado es %s\n", ptr[4]);
	free(ptr);

/*	char	str[] = "hola como estas";
	char	delim = ' ';
	char	*token;
	char	**ptr[3];
	int	position;
//	char	teststr[5] = {"hola"};
	char	*test = "hola";
	char	**testh;

	//test = &teststr;
	testh = &test;

	printf("test es %s\n", test);
	printf("testh es %s\n", *testh);

	position = 0;
	token = ft_strtok(str, delim);
	ptr[0] = &token;
	printf("token es %s\n", (char *)token);
	printf("ptr 0 es %s\n", *ptr[0]);
	token = ft_strtok(str, delim);
	ptr[1] = &token;
	printf("token es %s\n", (char *)token);
	printf("ptr 1 es %s\n", *ptr[1]);
	token = ft_strtok(str, delim);
	ptr[2] = &token;
	printf("token es %s\n", (char *)token);
	printf("ptr 2 es %s\n", *ptr[2]);*/
/*	token = ft_strtok(str, delim);
	while (position < 3)
	{
		ptr[position] = &token;
		printf("ptr %d es '%s'\n", position, *ptr[position]);
		token = ft_strtok(NULL, delim);
		position++;
	}*/
	return (0);
}

