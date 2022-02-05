/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:44:28 by irifarac          #+#    #+#             */
/*   Updated: 2022/02/05 13:59:47 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdio.h>
/*char	*ft_strtok(char *s, char c)
{
	static char	*buffer = NULL;
	char	*token;
	
	if (!buffer)
		buffer = s;
	token = buffer;
	if (!*buffer)
		return (0);
	while (*buffer && *buffer != c)
		buffer += 1;
	if (*buffer)
	{
		*buffer = 0;
		buffer += 1;
	}
	return (token);
}
*/
int	ft_counter(char const *s, char d)
{
	unsigned int	counter;
	char	*buffer;

	printf("Entro en ft_counter!!\n");
	printf("Caracter separador |%c|", d);
	counter = 0;
	/*buffer = (char *)s;
	while (*buffer)
	{
		//printf("Estoy en while de ft_counter\n");
		while (*buffer == d){
			buffer += 1;
		}
		if (*buffer){
			counter++;
		}
		while (*buffer & !(*buffer == d)){
			buffer += 1;
		}
	}
	printf("Salgo del while de ft_counter\n");
	*/
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	int	position;
	char	**ptr = NULL;
	char	*token;
	int	n_times;

	printf("El separador es:|%c|\n", c);
	printf("El string es: %s\n", s);
	ft_counter(s, ' ');
	printf("Hay %d palabras", n_times);
	position = 0;
	return (ptr);
}
