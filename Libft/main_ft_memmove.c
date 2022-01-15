/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 12:13:58 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/15 12:44:23 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t count);

int	main(void)
{
	char	dest[] = "abcde";
	char	dest1[] = "abcde";
	char	str[] = "memmove can be very useful.....";
	char	hola[] = "memmove can be very useful.....";
	char	target[] = "a shiny white sphere";
	char	target1[] = "a shiny white sphere";
	char	*p = target + 8;
	char	*source = target + 2;
	char	*t = target1 + 8;
	char	*source1 = target1 + 2;

	memmove(dest + 2, dest, 3);
	printf("\033[31;1;13mEl resultado es: %s\n\033[0m", dest);
	
	ft_memmove(dest1 + 2, dest1, 3);
	printf("\033[32;1;13mEl resultado ft_memmove es: %s\n\033[0m", dest1);
	
	memmove(str + 20, str + 15, 11);
	printf("\033[31;1;13mEl resultado es: %s\n\033[0m", str);
	
	ft_memmove(hola + 20, hola + 15, 11);
	printf("\033[32;1;13mEl resultado ft_memmove es: %s\n\033[0m", hola);

	memmove(p, source, 5);
	printf("\033[31;1;13mEl resultado es: %s\n\033[0m", target);

	ft_memmove(t, source1, 5);
	printf("\033[32;1;13mEl resultado ft_memmove es: %s\n\033[0m", target1);



	return (0);
}
