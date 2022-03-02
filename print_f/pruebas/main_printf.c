/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:41:38 by irifarac          #+#    #+#             */
/*   Updated: 2022/03/02 13:56:20 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>

int	prueba(const char *str, ...)
{
	va_list lst;
	int		result;

	va_start(lst, str);
	while (*str)
	{
		result += printf("%c", va_arg(lst, int));
		printf("\n%d\n", result);
		str++;
	}
	return (result);
}

int	main(void)
{
	int	result;
	int	ejemplo;
	int	*ptr;
	char	c = 'c';

	ejemplo = 2;
	ptr = &ejemplo;
	result = printf("123'%i'456'%d'\n", ejemplo, ejemplo);
	printf("result es %d\n", result);
	result = prueba("h", 'z');
	printf("result es %d\n", result);
	printf("%p\n", ejemplo);
	printf("%p\n", &ejemplo);
	printf("%p\n", &ptr);
	printf("%p\n", ptr);
	printf("%p\n", c);
	return (0);
}
