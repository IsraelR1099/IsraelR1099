/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:35:52 by irifarac          #+#    #+#             */
/*   Updated: 2021/12/16 10:43:47 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strcpy(char *dest, char *src);

int	main()
{
	char	src[5] = "hola";
	char	dest[5];

	printf("Array inicial:");
	printf("%s\n", src);
	
	ft_strcpy(dest, src);
	printf("%s\n", dest);
	return (0);
}
