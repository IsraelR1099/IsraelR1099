/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 09:39:40 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/14 09:51:39 by irifarac         ###   ########.fr       */
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
	printf("\033[31;1;13mEl resultado es: %s\n\033[0m", destination);

	ft_memcpy(destination2, source, 4);
	printf("\033[32;1;13mEl resultado con ft_memcpy es: %s\n\033[0m", destination2); 
	return (0);
}
