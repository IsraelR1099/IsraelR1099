/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:44:28 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/06 20:52:22 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtok(char *s, char c)
{
	static char	*buffer = NULL;
	char	*token;


	printf("la string  en ft strtok es igual a '%s'\n", s);	
	printf("el caracter  en strtok es igual a |%c|\n", c);	
	if (!buffer)
		buffer = s;
//	token = malloc(sizeof(char *) * 5);
	token = buffer;
//	printf("toke  es igual a '%s'\n", token);	
	if (!*buffer)
		return (0);
	while (*buffer == c && *buffer)
		buffer += 1;
	while (*buffer && *buffer != c)
		buffer += 1;
//	printf("buffer es igual a '%s'\n", buffer);
//	printf("Token1 es igual a '%s'\n", token);
	if (*buffer)
	{
		*buffer = 0;
		buffer += 1;
	}
//	printf("buffer 2 es igual a '%s'\n", buffer);
//	printf("Token2 es igual a '%s'\n", token);
	return (token);
}

int	ft_counter(char const *s, char c)
{
      unsigned int    counter;
      char    *buffer;
 
	  printf("El string en ft counter es '%s'\n", s);
	  printf("El separador es |%c|\n", c);
      counter = 0;
      buffer = (char *)s;
      while (*buffer)
      {
          while (*buffer == c)
              buffer += 1;
          if (*buffer)
              counter++;
          while (*buffer && !(*buffer == c))
          buffer += 1;
      }
	  printf("devuelvo counter %d\n", counter);
	  return(counter);
}
char	**ft_split(char const *s, char c)
{
	int	position;
	char	**ptr = NULL;
	char	*token;
	int	n_times;
	char	dup[ft_strlen(s) + 1];

	n_times = ft_counter(s, c);
	ft_strlcpy(dup, (char *)s, ft_strlen(s) + 1); 
	printf("la string despues de ft strlcpy es '%s'\n", dup);
	ptr = malloc(sizeof(char *) * (n_times + 1));
	if (!ptr)
		return (0);
	token = ft_strtok(dup, c);
	printf("token 1 despues de usar ft_split es '%s'\n", token);
	/*ptr[0] = token;
	printf("El separador es:|%c|\n", c);
	printf("El token 1 de ptr 0 es: '%s'\n", ptr[0]);
	printf("Hay %d palabras\n", n_times);*/
	position = 0;
	while (position < n_times)
	{
		ptr[position] = token;
		token = ft_strtok(NULL, c);
		position++;
	}
	printf("ptr 0 es '%s'\n", ptr[0]);
	printf("ptr 1 es '%s'\n", ptr[1]);
	printf("ptr 2 es '%s'\n", ptr[2]);
	ptr[position] = '\0';
	return (ptr);
}
