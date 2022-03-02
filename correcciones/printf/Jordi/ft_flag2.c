/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:19:42 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/03/01 18:08:24 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*set_dir(t_flag *flag, char	*str_flag)
{
	int		i;

	i = ft_strlen(str_flag);
	if (i > 0)
	{
		i--;
		if (str_flag[i] == '-')
		{
			flag->direction = '-';
			str_flag = sub(str_flag, 0, i--);
		}
		else
			flag->direction = '+';
		if (str_flag[i] == '+')
		{
			flag->sign = 1;
			str_flag = sub(str_flag, 0, i--);
		}
	}
	else
		flag->direction = '+';
	return (str_flag);
}

char	*set_zero(t_flag *flag, char *str_flag)
{
	int		i;

	i = ft_strlen(str_flag);
	if (i > 0)
	{
		i--;
		if (str_flag[i] == '0')
		{
			flag->zero = 1;
			str_flag = sub(str_flag, 0, i);
			if (i > 0)
			{
				i--;
				if (str_flag[i] == '-')
					flag->direction = '-';
				if (str_flag[i] == '+')
					flag->sign = 1;
			}
		}
		else
			flag->zero = 0;
	}
	return (str_flag);
}

char	*set_prec(t_flag *flag, char *str_flag)
{
	int	i;

	flag->prec = 1;
	str_flag = set_width(flag, str_flag);
	flag->size = flag->width;
	i = ft_strlen(str_flag);
	str_flag = sub(str_flag, 0, i - (ft_strlen(ft_strchr(str_flag, '.'))));
	return (str_flag);
}

char	*set_space(t_flag *flag, char *str_flag)
{
	if (str_flag[0] == ' ')
	{
		flag->space = 1;
		str_flag = sub(str_flag, 1, ft_strlen(str_flag) - 1);
	}
	return (str_flag);
}

char	*set_sharp(t_flag *flag, char *str_flag)
{
	if (str_flag[0] == '#')
	{
		flag->sharp = 1;
		str_flag = sub(str_flag, 1, ft_strlen(str_flag) - 1);
	}
	return (str_flag);
}
