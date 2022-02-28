/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amayo-ca <amayo-ca@student.42barc...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 10:53:26 by amayo-ca          #+#    #+#             */
/*   Updated: 2022/02/24 11:59:44 by amayo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_formats(va_list args, const char *s, int i)
{
	int	total;

	total = 0;
	if (s[i] == 'c')
		total += ft_print_char(va_arg(args, int));
	else if (s[i] == 's')
		total += ft_print_string(va_arg(args, char *));
	else if (s[i] == 'p')
		total += ft_print_ptr(va_arg(args, unsigned long long));
	else if (s[i] == 'd' || s[i] == 'i')
		total += ft_print_d(va_arg(args, int));
	else if (s[i] == 'u')
		total += ft_print_unsigned(va_arg(args, int));
	else if (s[i] == 'x' || s[i] == 'X')
		total += ft_print_hex(va_arg(args, unsigned int), s[i]);
	else if (s[i] == '%')
		total += ft_print_perc();
	return (total);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		total;

	i = 0;
	total = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			total += ft_formats(args, &s[0], i);
		}
		else
			total += write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (total);
}
