/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getobj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:10:31 by irifarac          #+#    #+#             */
/*   Updated: 2023/05/03 10:22:53 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	ft_move(char **tmp, char *estr, int *ret)
{
	*ret = 0;
	while ((*tmp < estr && !ft_compare(*tmp, "sp"))
		&& !ft_compare(*tmp, "pl") && !ft_compare(*tmp, "cy")
		&& !ft_compare(*tmp, "di"))
		*tmp = *tmp + 1;
}

static int	ft_list(char **tmp, char *estr, int ret)
{
	if (**tmp == 0)
		return (0);
	else if (**tmp == 's')
	{
		*tmp = *tmp + 2;
		return (ret);
	}
	else if (**tmp == 'p')
	{
		*tmp = *tmp + 2;
		return (ret);
	}
	else if (**tmp == 'c')
	{
		*tmp = *tmp + 2;
		return (ret);
	}
	else if (**tmp == 'd')
	{
		*tmp = *tmp + 2;
		return (ret);
	}
	else
		ft_move(tmp, estr, &ret);
	return (ret);
}

int	ft_getobj(char **str, char *estr, char **ftoken, char **eftoken)
{
	char	*tmp;
	int		ret;

	tmp = *str;
	while (tmp < estr && ft_strchr("\t\r\n\v ", *tmp))
			tmp++;
	if (ftoken)
		*ftoken = tmp;
	ret = *tmp;
	ret = ft_list(&tmp, estr, ret);
	while ((tmp < estr && !ft_compare(tmp, "sp"))
		&& !ft_compare(tmp, "pl") && !ft_compare(tmp, "cy")
		&& !ft_compare(tmp, "di"))
		tmp++;
	if (eftoken)
		*eftoken = tmp;
	*str = tmp;
	return (ret);
}
