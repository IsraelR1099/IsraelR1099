/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:45:39 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/03/01 18:16:29 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	len;

	len = 0;
	va_start(args, s);
	while (s[0] != '\0')
	{
		if (s[0] == '%')
		{
			s++;
			s = my_print((char *)s, args, &len);
		}
		else
		{
			ft_putchar_fd(s[0], 1);
			len++;
			s++;
		}
	}
	va_end(args);
	return (len);
}

char	*my_print(char *s, va_list args, size_t *len)
{
	t_flag	*flag;
	char	*str_flag;

	str_flag = get_s_flag(s);
	if (str_flag)
	{
		s += ft_strlen(str_flag);
		flag = init_flag(str_flag);
		*len += printf_type(args, flag);
		free(flag);
	}
	return (s);
}

size_t	printf_type(va_list args, t_flag *flag)
{
	if (flag->type == 'c')
		return (p_c(flag, va_arg(args, int)));
	if (flag->type == 's')
		return (p_s(flag, va_arg(args, char *)));
	if (flag->type == 'p')
		return (p_p(flag, va_arg(args, unsigned long long)));
	if (flag->type == 'd' || flag->type == 'i')
		return (p_di(flag, va_arg(args, int)));
	if (flag->type == 'u')
		return (p_u(flag, va_arg(args, unsigned long)));
	if (flag->type == 'x')
		return (p_lx(flag, va_arg(args, unsigned int)));
	if (flag->type == 'X')
		return (p_ux(flag, va_arg(args, unsigned int)));
	if (flag->type == '%')
		return (p_percent(flag));
	return (0);
}
