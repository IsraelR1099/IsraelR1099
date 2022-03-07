/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:31:25 by irifarac          #+#    #+#             */
/*   Updated: 2022/03/07 10:21:04 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		result;

	va_start(lst, str);
	result = 0;
	while (*str)
	{
		if (*str == '%')
		{
			result += ft_specifier(lst, *(str + 1));
			str += 1;
		}
		else
			result += ft_putchar(*str);
		str += 1;
	}
	va_end(lst);
	return (result);
}

int	ft_specifier(va_list lst, int str)
{
	int		result;
	char	*ptr;

	result = 0;
	if (str == 'c')
		result += ft_putchar(va_arg(lst, int));
	else if (str == 's')
		result += ft_putstr(va_arg(lst, char *));
	else if (str == 'p')
		result += ft_putptr(va_arg(lst, unsigned long long));
	else if (str == 'd' || str == 'i')
	{
		ptr = ft_print_itoa(va_arg(lst, int), 10);
		result += ft_putstr(ptr);
		free(ptr);
	}
	else if (str == 'u')
		result += ft_putunsigned(va_arg(lst, unsigned int));
	else if (str == 'x' || str == 'X')
		result += ft_puthex(va_arg(lst, unsigned int), str);
	else if (str == '%')
		result += ft_putchar('%');
	return (result);
}
