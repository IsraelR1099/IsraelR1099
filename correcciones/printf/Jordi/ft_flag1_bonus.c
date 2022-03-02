/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:19:42 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/03/01 17:55:47 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*set_prec(t_flag *flag, char *str_flag);
char	*set_space(t_flag *flag, char *str_flag);
char	*set_sharp(t_flag *flag, char *str_flag);

t_flag	*init_flag(char *str_flag)
{
	t_flag	*flag;

	flag = malloc(sizeof(t_flag));
	flag->zero = 0;
	flag->size = 0;
	flag->prec = 0;
	flag->sign = 0;
	flag->space = 0;
	flag->sharp = 0;
	str_flag = set_sharp(flag, str_flag);
	str_flag = set_space(flag, str_flag);
	str_flag = set_type(flag, str_flag);
	if (ft_strchr(str_flag, '.'))
		str_flag = set_prec(flag, str_flag);
	str_flag = set_width(flag, str_flag);
	str_flag = set_dir(flag, str_flag);
	str_flag = set_zero(flag, str_flag);
	if (flag->direction == '-')
		flag->zero = 0;
	if (!flag->prec)
		flag->size = flag->width;
	if (flag->zero && flag->sign)
		flag->space = 0;
	free(str_flag);
	return (flag);
}

char	*set_type(t_flag *flag, char	*str_flag)
{
	int		i;

	i = ft_strlen(str_flag);
	if (i > 0)
	{
		i--;
		flag->type = str_flag[i];
		str_flag = sub(str_flag, 0, i--);
	}
	return (str_flag);
}

char	*set_width(t_flag *flag, char *str_flag)
{
	char	*nbr;

	if (ft_strlen(str_flag) != 0)
	{
		nbr = get_flag_nbr(str_flag);
		flag->width = ft_atoi(nbr);
		if (flag->width != 0)
			str_flag = sub(str_flag, 0, ft_strlen(str_flag) - ft_strlen(nbr));
		free(nbr);
	}
	else
		flag->width = 0;
	return (str_flag);
}

char	*get_flag_nbr(char	*str_flag)
{
	int		i;
	char	*nbr;

	nbr = NULL;
	i = ft_strlen(str_flag) - 1;
	while (ft_isdigit(str_flag[i]) && i >= 0)
	{
		nbr = join(to_str(str_flag[i]), nbr);
		i--;
	}
	if (nbr && nbr[0] == '0')
		nbr = sub(nbr, 1, ft_strlen(nbr) - 1);
	if (!nbr)
		nbr = to_str('0');
	return (nbr);
}	

char	*get_s_flag(char *s)
{
	char	*str_flag;

	str_flag = NULL;
	while (s[0] != '\0')
	{
		str_flag = join(str_flag, to_str(s[0]));
		if (ft_strchr("cspdiuxX%", s[0]))
			break ;
		s++;
	}
	return (str_flag);
}
