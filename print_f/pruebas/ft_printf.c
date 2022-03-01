/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:31:25 by irifarac          #+#    #+#             */
/*   Updated: 2022/03/01 13:55:29 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	lst;
	int		position;
	int		result;

	va_start(lst, str);
	position = 0;
	result = 0;
	while (*str)
	{
		result += (*str == '%') ? ft_parameters(&lst, *str) : ft_putchr(1, *str, 1);
		s += 1;
	}
	va_end(lst);
	return (result);
}

int	ft_parameters(va_list *lst, char *str)
{


