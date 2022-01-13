/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:29:44 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/13 14:43:27 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *str1, const void *str2, size_t count);

int	main(void)
{
	char	ptr[] = "Hello World";
	char	ptr2[] = "Hello world";
	char	ptr1[] = "Hello World";
	char	ptr3[] = "Hello world";
	int	n;
	int	p;

	p = ft_memcmp(ptr1, ptr3, 8);
	n = memcmp(ptr, ptr2, 8);
	printf("Prueba con memcmp:\n");
	if (n > 0)
		printf("%s es mas grande que %s\n", ptr, ptr2);
	else if (n < 0)
		printf("%s es mas pequenio que %s\n", ptr, ptr2);
	else
		printf("Son iguales\n");
	printf("Prueba con ft_memcmp:\n");
	if (p > 0)
		printf("%s es mas grande que %s\n", ptr1, ptr3);
	else if (p < 0)
		printf("%s es mas pequenio que %s\n", ptr1, ptr3);
	else
		printf("Son iguales\n");

	return (0);
}
	
