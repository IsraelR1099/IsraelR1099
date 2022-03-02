/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p_type2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:43:20 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/03/01 18:07:06 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	p_lx(t_flag *flag, unsigned int ui)
{
	char	*str;

	if (ui == 0)
		flag->sharp = 0;
	str = to_hex(ui);
	if (flag->prec && !flag->size && !ui)
	{
		free(str);
		str = sdup("");
	}
	if (flag->sign && flag->zero && !flag->prec)
		flag->size -= 1;
	if (flag->zero || flag->prec)
		str = fill_zero(flag, str);
	if (flag->sign && ui > 0)
		str = join(to_str('+'), str);
	flag->size = ft_strlen(str);
	return (p_all(flag, str));
}

size_t	p_ux(t_flag *flag, unsigned int ui)
{
	char	*str;

	if (ui == 0)
		flag->sharp = 0;
	str = str_upper(to_hex(ui));
	if (flag->prec && !flag->size && !ui)
	{
		free(str);
		str = sdup("");
	}
	if (flag->sign && flag->zero && !flag->prec)
		flag->size -= 1;
	if (flag->zero || flag->prec)
		str = fill_zero(flag, str);
	if (flag->sign && ui > 0)
		str = join(to_str('+'), str);
	flag->size = ft_strlen(str);
	return (p_all(flag, str));
}

size_t	p_u(t_flag *flag, unsigned long ul)
{
	char	*str;

	str = u_itoa(ul);
	if (flag->prec && !flag->size && !ul)
	{
		free(str);
		str = sdup("");
	}
	if (flag->sign && flag->zero && !flag->prec)
		flag->size -= 1;
	if (flag->zero || flag->prec)
		str = fill_zero(flag, str);
	if (flag->sign && ul > 0)
		str = join(to_str('+'), str);
	flag->size = ft_strlen(str);
	return (p_all(flag, str));
}

size_t	p_percent(t_flag *flag)
{
	char	*str;

	str = to_str('%');
	if (flag->direction == '-')
		flag->zero = 0;
	if (flag->zero)
	{
		flag->size = flag->width;
		str = fill_zero(flag, str);
	}
	flag->size = ft_strlen(str);
	return (p_all(flag, str));
}
