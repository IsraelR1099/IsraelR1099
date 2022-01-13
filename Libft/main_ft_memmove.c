/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:13:58 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/13 14:05:35 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t count);

int	main(void)
{
	char	dest[] = "abcde";
	char	dest1[] = "abcde";
	char	dest2[] = "abcde";

	memmove(dest + 2, dest, 3);
	printf("El resultado es: %s\n", dest);
	
	ft_memmove(dest1 + 2, dest1, 3);
	printf("El resultado ft_memmove es: %s\n", dest1);
	
	memcpy(dest2 + 2, dest2, 3);
	printf("El resultado memcpy es: %s\n", dest2);

	return (0);
}
