/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 09:39:40 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/13 11:21:41 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t count);

int	main(void)
{
	char	source[] = "hola";
	char	destination[] = "como estas";
	char	destination2[] = "como estas";

	memcpy(destination, source, 4);
	printf("El resultado es: %s\n", destination);

	ft_memcpy(destination2, source, 4);
	printf("El resultado con ft_memcpy es: %s\n", destination2); 
	return (0);
}
