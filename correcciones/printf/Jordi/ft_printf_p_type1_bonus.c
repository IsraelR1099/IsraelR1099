/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p_type1_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:41:32 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/03/01 18:29:56 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	p_di(t_flag *flag, int n)
{
	char	*str;

	str = ft_itoa(n);
	if (flag->prec && !flag->size && !n)
	{
		free(str);
		str = sdup("");
	}
	if (flag->sign && flag->zero && !flag->prec)
		flag->size -= 1;
	if (flag->zero || flag->prec)
		str = fill_zero(flag, str);
	if (flag->sign && n >= 0)
		str = join(to_str('+'), str);
	flag->size = ft_strlen(str);
	return (p_all(flag, str));
}

size_t	p_p(t_flag *flag, unsigned long long p)
{
	char	*str;

	str = join(sdup("0x"), to_hex(p));
	flag->size = ft_strlen(str);
	return (p_all(flag, str));
}

size_t	p_s(t_flag *flag, char *str)
{
	if (!str)
		str = "(null)";
	flag->space = 0;
	if (!flag->prec)
		flag->size = ft_strlen(str);
	else if ((size_t)flag->size > ft_strlen(str))
		flag->size = ft_strlen(str);
	return (p_all(flag, sdup(str)));
}

size_t	p_c(t_flag *flag, int c)
{
	flag->size = 1;
	return (p_all(flag, to_str(c)));
}
