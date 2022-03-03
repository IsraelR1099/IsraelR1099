/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:31:25 by irifarac          #+#    #+#             */
/*   Updated: 2022/03/03 17:53:22 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	lst;
//	int		position;
	int		result;

	va_start(lst, str);
//	position = 0;
	result = 0;
	while (*str)
	{
		if (*str == '%' && *str + 1 != '%')
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
	/*else if (str == 'p')
		result += ft_putptr(va_arg(lst, void *));*/
	else if (str == 'd' || str == 'i')
	{
		ptr = ft_itoa(va_arg(lst, int), 10);
		result += ft_putstr(ptr);
	}
	else if (str == 'u')
		result += ft_putunsigned(va_arg(lst, unsigned int));
	else if (str == 'x' || str == 'X')
		result += ft_puthex(va_arg(lst, unsigned int));
	return (result);
}
