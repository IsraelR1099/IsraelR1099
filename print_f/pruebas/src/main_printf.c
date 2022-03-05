/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:41:38 by irifarac          #+#    #+#             */
/*   Updated: 2022/03/05 14:07:15 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include "../tc.h"

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
	int	result;
//	char	*ptr = "hola";

//	ft_printf("%slong min ftprintf %p\n%s", TC_GRN, (void *)LONG_MIN, TC_NRM);
//	printf("%slong min con printf %p\n%s", TC_RED, (void *)LONG_MIN, TC_NRM);
//	ft_printf("%svoid con ftprintf %p\n%s", TC_GRN, -14523, TC_NRM);
	ft_printf("%svoid con ftprintf %p\n%s", TC_GRN, (void *)-14523, TC_NRM);
	printf("%svoid con printf %p\n%s", TC_RED, (void *)-14523, TC_NRM);
	ft_printf("hexadeciamal %x %x\n", -5, 12);
	printf("hexadeciamal %x %x\n", -5, 12);
//	ft_printf("%sunsigned number %u\n%s", TC_RED, -1532, TC_NRM);
//	printf("%sunsigned number con printf %u\n%s", TC_GRN, -1532, TC_NRM);
	ft_printf("%snumero con ftprintf %d %i\n%s", TC_RED, -15525, -51232, TC_NRM);
	ft_printf("numeros con ftprintf es %d, %d, %d, %d\n", 0, -1, 1, 100);
//	ft_printf("%svoid positivo con ftprintf %p\n%s", TC_GRN, (void *)14523, TC_NRM);
//	printf("%svoid positivo con printf %p\n%s", TC_RED, (void *)14523, TC_NRM);
	

	result = printf("%d", -2000);
	printf("result es %d\n", result);
	result = ft_printf("%d", -2000);
	printf("result es %d\n", result);
	
	
	return (0);
}
