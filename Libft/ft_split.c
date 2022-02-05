/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:44:28 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/05 14:48:42 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
char	*ft_strtok(char *s, char c)
{
	static char	*buffer = NULL;
	char	*token;

	printf("la string  es igual a '%s'\n", s);	
	printf("el caracter  es igual a '%c'\n", c);	
	printf("Token1 es igual a '%s'\n", token);	
	if (!buffer)
		buffer = s;
	token = malloc(sizeof(char *) * 5);
	token = buffer;
	printf("toke  es igual a '%s'\n", token);	
	if (!*buffer)
		return (0);
	while (*buffer && *buffer != c)
		buffer += 1;
	if (*buffer)
	{
		*buffer = 0;
		buffer += 1;
	}
	printf("Token2 es igual a '%s'\n", token);	
	return (token);
}

int	ft_counter(char const *s, char c)
{
      unsigned int    counter;
      char    *buffer;
 
	  printf("El string es%s\n", s);
	  printf("El separador es %c\n", c);
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

	n_times = ft_counter(s, c);
	ptr = malloc(sizeof(char *) * (n_times + 1));
	if (!ptr)
		return (0);
	token = ft_strtok((char *)s, c);
	ptr[0] = token;
//	printf("El separador es:|%c|\n", c);
	printf("El token 1 es: %s\n", ptr[0]);




	printf("Hay %d palabras", n_times);
	position = 0;
	return (ptr);
}
