/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getobj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:10:31 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/08 10:56:35 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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
	if (*tmp == 0)
		return (0);
	else if (*tmp == 's' && *(tmp + 1) == 'p')
		tmp += 2;
	else if (*tmp == 'p' && *(tmp + 1) == 'l')
		tmp += 2;
	else if (*tmp == 'c' && *(tmp + 1) == 'y')
		tmp += 2;
	else
	{
		ret = 0;
		while ((tmp < estr && !ft_compare(tmp, "sp"))
			&& !ft_compare(tmp, "pl") && !ft_compare(tmp, "cy"))
			tmp++;
		printf("no object case\n");
	}
	while ((tmp < estr && !ft_compare(tmp, "sp"))
		&& !ft_compare(tmp, "pl") && !ft_compare(tmp, "cy"))
		tmp++;
	if (eftoken)
		*eftoken = tmp;
	*str = tmp;
	return (ret);
}
