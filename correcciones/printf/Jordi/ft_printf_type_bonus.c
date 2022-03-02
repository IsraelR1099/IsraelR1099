/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjane-ta <jjane-ta@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:46:49 by jjane-ta          #+#    #+#             */
/*   Updated: 2022/03/01 17:09:33 by jjane-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*str_upper(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (ft_isalpha(str[i]))
			str[i] = (char) ft_toupper((int)str[i]);
		i--;
	}
	return (str);
}

char	*to_hex(unsigned long long n)
{
	char	*str;
	int		aux;

	if (n == 0)
		return (str = sdup("0"));
	str = sdup("");
	while (n > 0)
	{
		aux = n % 16;
		if (aux > 9)
			str = join(to_str(aux + 'a' - 10), str);
		else
			str = join(to_str(aux + '0'), str);
		n /= 16;
	}
	return (str);
}

char	*u_itoa(unsigned int n)
{
	char	*str;

	if (n == 0)
		return (str = sdup("0"));
	str = sdup("");
	while (n > 0)
	{
		str = join(to_str((n % 10) + '0'), str);
		n /= 10;
	}
	return (str);
}
