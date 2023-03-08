/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getident.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irifarac <irifarac@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:30:16 by irifarac          #+#    #+#             */
/*   Updated: 2023/03/08 10:56:19 by irifarac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_getident(char **str, char *estr, char **ftoken, char **eftoken)
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
	else if (*tmp == 'A')
		tmp++;
	else if (*tmp == 'C')
		tmp++;
	else if (*tmp == 'L')
		tmp++;
	else
	{
		ret = 0;
		while (tmp < estr && !ft_strchr("ACL", *tmp))
			tmp++;
		printf("no ambient case\n");
	}
	while (tmp < estr && !ft_strchr("ACL", *tmp))
			tmp++;
	if (eftoken)
		*eftoken = tmp;
	*str = tmp;
	return (ret);
}
