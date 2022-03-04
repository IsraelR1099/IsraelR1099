/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:41:38 by irifarac          #+#    #+#             */
/*   Updated: 2022/03/04 14:14:17 by irifarac         ###   ########.fr       */
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
//	int	result;
	int	ejemplo;
	char	*ptr = NULL;

	ejemplo = 15560;
	/*result = ft_printf("hola%d\n", -50);
	printf("%sresult mi printf es %d\n%s", TC_RED, result, TC_NRM);
	result = printf("hola%d\n", -50);
	printf("%sresult real es %d\n%s", TC_GRN, result, TC_NRM);
	ft_printf("hexadecimal '%X'\n", ejemplo);
	printf("%shexadecimal con printf real %X\n%s",TC_GRN, ejemplo, TC_NRM);*/
	ft_printf("hola %s", ptr);
	return (0);
}
