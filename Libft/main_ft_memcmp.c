/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:29:44 by irifarac          #+#    #+#             */
/*   Updated: 2022/01/31 13:32:44 by irifarac         ###   ########.fr       */
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
	char	s[] = {-128, 0, 127, 0};
	char	s2[] = {0, 0, 127, 0};
	int	n;
	int	p;
	int	m;
	int	z;

	p = ft_memcmp(ptr1, ptr3, 8);
	n = memcmp(ptr, ptr2, 8);
	m = memcmp(s, s2, 1);
	z = ft_memcmp(s, s2, 1);

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

	printf("Prueba con memcmp:\n");
	if (m > 0)
		printf("s es mas grande que s2\n");
	else if (m < 0)
		printf("s es mas pequenio que s2\n");
	else
		printf("Son iguales\n");
	printf("Prueba con ft_memcmp:\n");
	if (z > 0)
		printf("s es mas grande que s2\n");
	else if (z < 0)
		printf("s es mas pequenio que s2\n");
	else

	return (0);
}
	
