/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:12:12 by dbekic            #+#    #+#             */
/*   Updated: 2022/10/23 12:39:31 by dbekic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

static int	ft_putstring(int fd, char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(fd, "(null)", 6));
	while (str[i] != 0)
		i++;
	if (write(fd, str, i) < 0)
		return (-1);
	return (i);
}

static int	ft_argcheck(int fd, va_list arg, char c)
{
	int	i;

	i = 0;
	if (c == 's')
		i = ft_putstring(fd, va_arg(arg, char *));
	return (i);
}

int	ft_printf(int fd, const char *format, ...)
{
	int		i;
	int		j;
	va_list	arg;

	i = 0;
	j = 0;
	va_start(arg, format);
	while (format[i] != 0)
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			j += ft_argcheck(fd, arg, format[i + 1]);
			i += 2;
			continue ;
		}
		if (write(fd, &format[i], 1) < 0)
			return (-1);
		i++;
		j++;
	}
	va_end(arg);
	return (j);
}
