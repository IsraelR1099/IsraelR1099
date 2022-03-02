/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:45:39 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/03/01 17:18:28 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	p_all(t_flag *flag, char *str)
{
	size_t	len;

	if (flag->sharp)
		flag->width -= 2;
	len = 0;
	if (flag->space && str[0] != '-' && str[0] != '+' )
	{
		len += write(1, " ", 1);
		flag->width--;
	}
	if (flag->direction == '+')
		len += p_blanks(flag->width - flag->size);
	if (flag->sharp)
	{
		if (flag->type == 'x')
			len += write(1, "0x", 2);
		if (flag->type == 'X')
			len += write(1, "0X", 2);
	}
	len += write(1, str, flag->size);
	if (flag->direction == '-')
		len += p_blanks(flag->width - flag->size);
	free(str);
	return (len);
}

size_t	p_blanks(int n)
{
	int		i;
	size_t	len;

	len = 0;
	i = 0;
	while (i++ < n)
		len += write(1, " ", 1);
	return (len);
}

char	*fill_zero(t_flag *flag, char *str)
{
	int		i;
	char	*sign;

	sign = NULL;
	i = ft_strlen(str);
	if (i > 0)
	{
		if (str[0] == '-' || str[0] == '+')
		{
			sign = to_str(str[0]);
			str = sub(str, 1, ft_strlen(str) - 1);
		}
	}
	if (flag->prec)
		i = ft_strlen(str);
	else if (flag->space && flag->zero && !sign)
		i++;
	else if (flag->sharp)
		i += 2;
	while (i++ < flag->size)
		str = join(to_str('0'), str);
	return (join(sign, str));
}
