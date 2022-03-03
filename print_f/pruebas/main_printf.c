/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:41:38 by irifarac          #+#    #+#             */
/*   Updated: 2022/03/03 14:12:43 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdarg.h>

int	prueba(const char *str, ...)
{
	va_list lst;
	int		result;

	va_start(lst, str);
	result = 0;
	while (*str)
	{
		result += printf("%c", va_arg(lst, int));
		printf("\n%d\n", result);
		str++;
	}
	return (result);
}

void	test(unsigned int n)
{
	printf("prueba %u\n", n);
	printf("prueba %i\n", n);
}


int	main(void)
{
//	int	result;
//	int	ejemplo;
//	unsigned int ejemplo2;
//	int	*ptr;
//	char	c = 'c';

	/*ejemplo = -2;
	ejemplo2 = -4;
	ptr = &ejemplo;
	test(ejemplo2);
	result = printf("resultado es '%i'\n", ejemplo2);
	result = printf("resultado2 es '%u'\n", ejemplo2);
	result = printf("resultado3 es '%u'\n", ejemplo);
	result = printf("hola %s\n", "hola");
	printf("result es %d\n", result);
	printf("hexadecimal es %x %X\n", 152, 152);
	result = prueba("h", 'z');
	printf("result es %d\n", result);
	printf("%x\n", INT_MIN);
	printf("%x\n", -1);
	printf("hola%d\n", ejemplo);
	printf("%p\n", &ptr);
	printf("%p\n", ptr);
	printf("%p\n", c);*/
	//ft_printf("hola %d\n", 256);
	//ft_printf("str es %s\n", "como estas");
	//ft_printf("unsigned es %u\n", -2);
	//printf("real %u\n", -2);
	ft_printf("hexadecimal '%x'\n", 176);
	return (0);
}
